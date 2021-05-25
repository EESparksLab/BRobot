
#include <SoftwareSerial.h>

int VRx = A0;  // turning commands
int VRy = A1;  // forward velocity commands
int SW_0 = 8;  //  switch digital pin, turn rc on
int SW_1 = 9;  //  switch digital pin, TBD
int LED_PIN = 10;
int xPosition = 0;
int yPosition = 0;
int sw0_state = 0;
int sw1_state = 0;
int mapX = 0;
int mapY = 0;
int constrainX = 0;
int constrainY = 0;

int timecom = 0;
int datatime = millis();

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // read the input on analog pin 0:
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);  // flipping sign so 0 is left
  //Serial.print(xPosition);
  //Serial.print(",");
  //Serial.println(yPosition);
  sw0_state = digitalRead(SW_0);
  if (sw0_state == 1) 
  {
    digitalWrite(LED_PIN, HIGH);
  }
  else{
    digitalWrite(LED_PIN, LOW);
    }
  sw1_state = digitalRead(SW_1);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 1023, 0, -512, 512);
  constrainX = constrain(mapX, -512, 512);
  constrainY = constrain(mapY, -512, 512);
  delay (10);
  
  timecom = millis() - datatime;//contol data transfer rate
  
  if (timecom>200){
    Serial.print("<");
    Serial.print(constrainX);
    Serial.print(",");
    Serial.print(constrainY);
    Serial.print(",");
    Serial.print(sw0_state);
    Serial.print(",");
    Serial.print(sw1_state);
    Serial.println(">");
    //Serial.print("Controls sent");
    
    datatime = millis();        // delay in between reads for stability
  }
  
}
