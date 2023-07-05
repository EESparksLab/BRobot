// Humble beginning of Brobot control panel 
// the setup function runs once when you press reset or power the board
int value = 0;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);  
}

// the loop function runs over and over again forever
void loop() {
  if (Serial.available()) { // if there's data coming in from the serial connection
    String inputString = Serial.readStringUntil('\n');
    switch(inputString[0]) {
      case 'r': 
        value = digitalRead(2); 
        digitalWrite(2, !value);
        break;
      case 'l':
        value = digitalRead(3);
        digitalWrite(3, !value);
    }
  }
}