//Oliver Olsen s205443
//Nils Wulff   s223968

/*
*   7a. The value to repressent a colour is based on the number of bytes.
*   We use 8 bytes to control our colour values. With 8 bytes we can write 256 number (0-255).
*
*   7b. THe Serial.parseInt(). It skips everything that is not an int or a minus.
*   This means that if a a string of characters is enter eg. "akhdb23n3n" then the parseInt()
*   skips all the letters and returns in this example 233. 
*/

#include <Arduino.h>



void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
}

