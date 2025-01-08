#include<Arduino.h>

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
}

