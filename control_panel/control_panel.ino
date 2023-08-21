// Humble beginning of Brobot control panel 
// the setup function runs once when you press reset or power the board
int value = 0;
int PIN_R = 2;
int PIN_L = 3;
int PIN_PRECHARGE = 12;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_L, OUTPUT);
  pinMode(PIN_PRECHARGE, OUTPUT);
  digitalWrite(PIN_PRECHARGE, HIGH);
  digitalWrite(PIN_R, LOW);
  digitalWrite(PIN_L, LOW);  
}

// the loop function runs over and over again forever
void loop() {
  if (Serial.available()) { // if there's data coming in from the serial connection
    digitalWrite(PIN_PRECHARGE, LOW);
    String inputString = Serial.readStringUntil('\n');
    switch(inputString[0]) {
      case 'r': 
        digitalWrite(PIN_R, 1);
        break;
      case 'l':
        digitalWrite(PIN_L, 1);
        break;
      case 'R':
        errorBlink(PIN_R);
        break;
      case 'L':
        errorBlink(PIN_L);
        break;
      case '[':
        digitalWrite(PIN_L,0);
        break;
      case ']':
        digitalWrite(PIN_R,0);
        break;
    }  
  }
}
void errorBlink(int pin){
  int flash = 1;
  for(int i=0;i<3;i++){
    flash = !flash;
    delay(200);
    digitalWrite(pin,flash);
  }
  digitalWrite(pin,0);
  return;
}