//Oliver Olsen s205443
//Nils Wulff   s223968

/*
*   7a. The value to repressent a colour is based on the number of bytes.
*   We use 8 bytes to control our colour values. With 8 bytes we can write 256 number (0-255).
*   This is range, is for each of the 3 colors (red, greenand blue). So there is 256*256*256 different combinations.
*
*   7b. THe Serial.parseInt(). It skips everything that is not an int or a minus.
*   It returns the next valid int.
*/

#include <Arduino.h>

int incomingByte = 0;


  
  
#define LED_RED 11
#define LED_GREEN 12
#define LED_BLUE 13


int pins[3] = {
  LED_RED, 
  LED_GREEN, 
  LED_BLUE
}; 


void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 3; i++) {
    pinMode(pins[i], OUTPUT); 
    digitalWrite(pins[i], LOW); 
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    incomingByte = Serial.parseInt();
    Serial.print(incomingByte);
}
}

