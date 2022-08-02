// This code is uploaded to the Arduino Nano inside the SMURF
// Calibration should be done beforehand to determine preload and loadcell calibration factor
//You should also tune the motor with Basic Micro Motion Studio (windows app) before assembly

//Includes required to use Roboclaw library
#include <SoftwareSerial.h> //needed for serial connection to the BT module
#include "RoboClaw.h"      //motor driver thats all over SparksLab
#include "HX711.h"         //Load cell library
#include <Arduino.h>
#include "Adafruit_BLE.h"    //BT module library
#include "Adafruit_BluefruitLE_UART.h"   //needed for Serial UART connection to BT module
#include "Adafruit_ATParser.h"           //derivative class of BT module for managing buffer

// Set software serial and init instances of roboclaw/loadcell
SoftwareSerial serial(10,11);
RoboClaw roboclaw(&serial,10000);
HX711 scale;

//ripped this relavent part of Adafruit_BLE.h
#define BUFSIZE                        128   // Size of the read buffer for incoming data
#define VERBOSE_MODE                   true  // If set to 'true' enables debug output
#define BLUEFRUIT_SWUART_RXD_PIN       9    // Required for software serial!
#define BLUEFRUIT_SWUART_TXD_PIN       8   // Required for software serial!
#define BLUEFRUIT_UART_CTS_PIN         7   // Required for software serial!
#define BLUEFRUIT_UART_MODE_PIN        -1
#define BLUEFRUIT_UART_RTS_PIN         -1

//setting up the software serial connection to Bluefruit Friend and initializing object
SoftwareSerial bluefruitSS = SoftwareSerial(BLUEFRUIT_SWUART_TXD_PIN, BLUEFRUIT_SWUART_RXD_PIN);
Adafruit_BluefruitLE_UART ble(bluefruitSS, BLUEFRUIT_UART_MODE_PIN,BLUEFRUIT_UART_CTS_PIN, BLUEFRUIT_UART_RTS_PIN);

// Set address and PID constants for roboclaw
// You can download the basic motion interface if you want to play with these values
// https://www.basicmicro.com/downloads
#define address 0x80
#define Kp 8.53432
#define Ki 0.85340
#define Kd 0.0
#define Kp_pos 8.54554
#define Ki_pos 0.0
#define Kd_pos 0.0
#define qpps 3375  // 2790 for 5:1 ratio motor
#define min_volts 9.0  // assume 3S LiPo battery
#define max_volts 13.0
 
// Set pins and calibration factor for loadcell
#define DOUT  3
#define CLK  2
float calibration_factor = -103916.35; 
float calibration_offset = -101652.30;
                                    

// Variables that might adjust depending on motor/geaar ratio selection
// BILDA 5202 Series Yellow Jacket 117RPM @12VDC planetary gear motor (high torque version)
int enc_limit = 21000;  // maximum encoder counts before pusher leg bottoms out 3400, added some buffer

float preload = 1.41; //1.26 for small;  // calibrate loadcell, then use '4' command to display loadcell value when smurf is upright under load from only its own weight (kg) - positive number
float distance_per_count = 0.0055/1000;  //distance pusher moves per encoder count (mm/1000=m) -> 0.0547/1000 for 5rpm
 

float lever_arm = 0.150;  // distance between center of stalk and pusher foot (m)

// Initialization variables
String input;
String currentCommand;
int pos = 0;
int init_height = 0;
uint32_t enc1;
uint8_t M1Status;
bool M1Valid;
uint32_t enc2;
float loads [9];  // loads that will be saved for each bending trial
float bend_angle = 0;  // bend angle in degrees
float pi = 3.1415;
int push_counts = 0;

// For bt module 
int32_t CMDCharId;
int32_t DATACharId;
int32_t DATAChar2Id;


// Display loadcell in kgs and adjust readings based on calibration factor
void display_loadcell(){
  scale.set_scale(calibration_offset);
  scale.set_offset(calibration_offset);
  scale.tare();
  //Adjust to this calibration factor
  //Serial.print("Load reading: ");
  //Serial.print(scale.get_units(), 1);  // the 1 rounds to one decimal place
  //Serial.print(" kgs"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  //Serial.println();
}//display_loadcell()


// Home SMURF and reset encoder values to zero
void home_encoder(){
  //roboclaw.SetEncM1(address,0);
  roboclaw.listen();   //switch to listening to roboclaw; required to recieve encoder data
  int enc_last = 0;
  int enc_now = 1;
  roboclaw.DutyM1(address,-16000);      //50% duty cycle in the negative direction
  while (enc_last != enc_now){
    delay(500);
    enc_last = enc_now;
    enc1 = roboclaw.ReadEncM1(address);  // can use encoders for error detection
    enc_now = enc1;
     Serial.print("enc_now =");Serial.println(enc_now);     //debug
     Serial.print("enc_last =");Serial.println(enc_last);   //debug
  }//while (enc_last != enc_now)
  roboclaw.DutyM1(address,0);       //set duty cycle to zero; stop motor
  roboclaw.SetEncM1(address,0);
}//home_encoder()


// Get serial input from Bluetooth user interface
void get_input(){
      bluefruitSS.listen(); //switch software serial to listen to BT module
      uint16_t bufSize = 20;  //Buffer of max size for characteristic
      uint16_t timeout = 1000;  //one second timeout delay
      char inputBuffer[bufSize];
      //Read Ble buffer after query for command characteristic
      ble.atcommandStrReply("AT+GATTCHAR=3",inputBuffer,bufSize,timeout);
      input = inputBuffer;
      Serial.print("Unparsed Input: ");    // debug
      Serial.println(input);         // debug
      int codeIndex = input.indexOf("3");  //Finds the index of where the ATcommand ends
      Serial.print("index of code: ");     // debug
      Serial.println(codeIndex);          //debug
      char parsedInput_1 = input.charAt(codeIndex+2); //get first digit
      char parsedInput_2 = input.charAt(codeIndex+3); //get second digit
      //Commands are supposed to be one digit but for some unkown reason the received integers 0-8
      //correspond to outputs 48-56
      String parsedInput;
      parsedInput += parsedInput_1;        //add first digit to parsing string
      parsedInput += parsedInput_2;        //add second digit to parsing string
      Serial.print("Parsed Input: ");      //debug
      Serial.println(parsedInput);         //debug
      int scaledInput = parsedInput.toInt() - 48;     //corrects input back to 0-8
      Serial.print("Scaled Input: ");      //debug
      Serial.println(scaledInput);          //debug
      String finalInput = String(scaledInput);       // cast back to string
      Serial.print("Final Input: ");       //debug
      Serial.println(finalInput);          //debug
      if (finalInput != currentCommand) {     //command should only be executed 1 time after recieved
        input = finalInput;                   //This might cause error with repeating tests
        currentCommand = finalInput;
        ble.println(F ("AT+GATTCHAR=3,5"));     // resets the BT model to something else
        ble.flush();                            //Resets required to flush the buffer
      }else{input = "";}
}//get_input()

// Lower pushing foot until loadcell reads zero, the weight of the device will give a negative reading
// so when the load cell reads zero these effects are balanced
void get_init_height(){
  roboclaw.listen();   //switch to listening to roboclaw; required to recieve encoder data
  while ((scale.get_units()-preload < 0) && (enc1 < enc_limit)){
    //Serial.println(scale.get_units()-preload);    //debug
    roboclaw.DutyM1(address, 16000);     //roughly 50% duty cycle
    enc1 = roboclaw.ReadEncM1(address, &M1Status, &M1Valid);
    Serial.print(scale.get_units()-preload);Serial.println(scale.get_units()-preload < 0);
//     if (enc1 > enc_limit){
//       //Serial.println("ERR: smurf could not find the ground, please place it lower on the stalk");
//       //Serial.println(enc1); // for debug
//       break;
//     }//if (enc1 > enc_limit)
  }//while (scale.get_units()-preload < 0)
  roboclaw.DutyM1(address, 0); // Duty cycle 0
  delay(500);
  
  init_height = roboclaw.ReadEncM1(address, &M1Status, &M1Valid);
  Serial.println(init_height);
}//get_init_height()

void move_to(int pos){
  //These speeds and accelaration parameters are measured in encoder counts/second and encoder counts/sec^2
  roboclaw.SpeedAccelDeccelPositionM1(address, 1500, 3000, 1500, pos, 0); //(address, 50000, 1000, 50000, pos, 0); //for 5:1 ratio gears SpeedAccelDeccelPositionM1(address, accel, speed, deccel, position, flag);
  delay(1000);
}//move_to(int pos


void small_flextest(){
  move_to(init_height);
  float bend_angles[] = {2.0, 2.5, 3.0, 3.5, 4.0}; // this should match the SMURF code, note i below this line is len(bend_angles)-1
  ble.print(F("AT+GATTCHAR="));            //writes to the DATA BT Service 
  ble.print( DATACharId );
  ble.print( ",");
  Serial.println("starting smallFlexTest");   //debug
  for (int i = 0; i < 3; i++){
    get_bend_counts(bend_angles[i]);
    move_to(init_height + push_counts);
    delay(100);
    ble.print(scale.get_units()-preload);  // init_height drops leg until preload value is measured, this offsets the weight of smurf. We need to subtract this load to get the amount of force pushing against the plant.
    ble.print(",");
  }//for (int i = 0; i < 4; i++)
  get_bend_counts(bend_angles[3]);
  move_to(init_height + push_counts);
  delay(100);
  ble.println(scale.get_units()-preload);  //subtract smurf weight here too
  ble.flush();                            //Resets required to flush the buffer
  Serial.println("finshing smallFlexTest");
  move_to(init_height);
}//small_flextest()


void large_flextest(){
  move_to(init_height);
  float bend_angles[] = {2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0, 5.5, 6.0}; // this should match the SMURF code, note i below this line is len(bend_angles)-1
  ble.print(F("AT+GATTCHAR="));            //writes to the DATA BT characteristic
  ble.print( DATACharId );
  ble.print( ",");
  for (int i = 0; i < 4; i++){
    get_bend_counts(bend_angles[i]);
    move_to(init_height + push_counts);
    delay(100);
    ble.print(scale.get_units()-preload);  // init_height drops leg until preload value is measured, this offsets the weight of smurf. We need to subtract this load to get the amount of force pushing against the plant.
    ble.print(",");
  }//for (int i = 0; i < 4; i++)
  ble.println();
  ble.flush();
  ble.print(F("AT+GATTCHAR="));            //writes to the second DATA BT characteristic
  ble.print( DATAChar2Id );
  ble.print( ",");
  for (int i = 4; i < 7; i++){
    get_bend_counts(bend_angles[i]);
    move_to(init_height + push_counts);
    delay(100);
    ble.print(scale.get_units()-preload);  // init_height drops leg until preload value is measured, this offsets the weight of smurf. We need to subtract this load to get the amount of force pushing against the plant.
    ble.print(",");
  }//for (int i = 4; i < 8; i++)
  get_bend_counts(bend_angles[7]);
  move_to(init_height + push_counts);
  delay(100);
  ble.println(scale.get_units()-preload);  //subtract smurf weight here too
  ble.flush();                            //Resets required to flush the buffer
  move_to(init_height);
}//large_flextest()


void get_bend_counts(float bend_angle){
  float push_length = lever_arm * tan(pi*bend_angle/180);
  push_counts = round(push_length/distance_per_count);
  //Serial.print(push_counts);
}//get_bend_counts(float bend_angle


// This is the first function arduino runs on reset/power up
void setup() {
  
  //Open Serial and roboclaw at 38400bps
  Serial.begin(115200);
  roboclaw.begin(38400);      // recommended buad rate from basic micro; needs to be set on the roboclaw using motion studio
  
  scale.begin(DOUT, CLK);
  
  display_loadcell();
  delay(10);

  //Set PID Coefficients
//  roboclaw.SetM1VelocityPID(address,Kp,Ki,Kd,qpps);
//  roboclaw.SetM1PositionPID(address, Kp_pos, Ki_pos, Kd_pos, 0,0,0,qpps); //SetM1PositionPID(uint8_t address,float kp_fp,float ki_fp,float kd_fp,uint32_t kiMax,uint32_t deadzone,uint32_t min,uint32_t max)

  //Setup for the Bluetooth module
  ble.begin();
  ble.factoryReset();      //factory reset required for consistent boot
  //Sets the name of the device; make sure the next 2 lines match
  Serial.println(F("Setting device name to 'Bluefruit SMURF_FatBoy': "));
  ble.println(F("AT+GAPDEVNAME=Bluefruit SMURF_FatBoy"));
  Serial.println( F("Adding Service 0x1234 with 3 chars 0x2345 & 0x6789 & 0xABCD") );
  //creates service
  ble.println( F("AT+GATTADDSERVICE=uuid=0x1234") );
  ble.reset();                             //reset required to flush buffer
  //Adds data characteristic; properties 0x02 = Broadcast for Read; limited to 20 bytes
  ble.println( F("AT+GATTADDCHAR=UUID=0x2345,PROPERTIES=0x02,MIN_LEN=1,MAX_LEN=20,DATATYPE=string,DESCRIPTION=Measurements,VALUE=abc"));
  DATACharId = 1;        //Ble assigns ID's on a first come first served basis
  Serial.print("data characteristic has ID:");
  Serial.println(DATACharId);
  ble.reset();                          //reset required to flush buffer
  //second data characteristic for use in large flextest
  ble.println( F("AT+GATTADDCHAR=UUID=0xABCD,PROPERTIES=0x02,MIN_LEN=1,MAX_LEN=20,DATATYPE=string,DESCRIPTION=Measurements2,VALUE=abc"));
  DATAChar2Id = 2;
  Serial.print("data characteristic has ID:");
  Serial.println(DATAChar2Id);
  ble.reset();                          //reset required to flush buffer
  //adds the command characteristic; properties 0x08 = Broadcast for Write; just an int
  ble.println( F("AT+GATTADDCHAR=UUID=0x6789,PROPERTIES=0x08,MIN_LEN=4,MAX_LEN=4,DATATYPE=INTEGER,DESCRIPTION=CommandValue,VALUE=3"));
  CMDCharId = 3;
  Serial.print("Command characteristic has ID:");
  Serial.println(CMDCharId);
  ble.reset();                        //reset required to flush buffer
  //advertise these changes over the broadcast
  ble.println( F("AT+GAPSETADVDATA=02-01-06-05-02-0d-18-0a-18") );
  /* Reset the device for the new service setting changes to take effect */
  Serial.println(F("Performing a SW reset (service changes require a reset): "));
  ble.reset();
}//void setup()

// Main loop
void loop() {
  get_input();
  if (input.length() >0) {
//       Serial.print("input:");
//       Serial.println(input); //see what was received for debug
      if (input == "0") {  // Calibrate encoder home and tare load cell
        home_encoder();
        display_loadcell();
        scale.tare(); //Reset the scale to 0
      }
      else if (input ==  "1") {  // Find initial height
        get_init_height();
      }
      else if (input ==  "2") {  // Move to init height position
        move_to(0);
        scale.tare(); //Reset the scale to 0
        init_height = 0;
      }
      else if (input ==  "3") {  // Move to home position
        move_to(enc_limit);
      }
      else if (input == "4") {  // display current loadcell reading
        Serial.println("dispLoadcell signal recieved");
        display_loadcell();
        Serial.println(scale.get_units());
      }
      else if (input == "8") {  // start flextest small deflection
        small_flextest();  // get and send loads over serial to python script for anaylysis
      }

      else if (input == "9") {  // start flextest large deflection
        large_flextest();  // get and send loads over serial to python script for anaylysis
      }
      else if (input == "7") {
        roboclaw.listen();
        move_to(1000); 
      }
      else if (input == "6") {
        Serial.println(roboclaw.ReadEncM1(address));
        roboclaw.DutyM1(address,0);
      }
      input = "";
      
  }//if (input.length() >0)
}//loop()
