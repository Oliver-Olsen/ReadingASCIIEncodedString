//Code is made for the Arduino Mega 2560

//Oliver Olsen s205443
//Nils Wulff   s223968

/*
*   7a. The value to repressent a colour is based on the number of bytes.
*   We use 8 bytes to control our colour values. With 8 bytes we can write 256 number (0-255).
*   This is range, is for each of the 3 colors (red, greenand blue). So there is 256*256*256 different combinations.
*
*   7b. The Serial.parseInt(). It skips everything that is not an int or a minus.
*   It returns the next valid int.
*/

#include <Arduino.h>

// Defines pins
#define LED_RED 11
#define LED_GREEN 12
#define LED_BLUE 13

// Values which determine the behaviour of the fade
int fadeTime = 200; //Sets the total time the fade will take
int fadeSteps = 10; //Sets how many steps are inbetween the current and wished values

//An array containing the pins
int pins[3] = {
  LED_RED, 
  LED_GREEN, 
  LED_BLUE
}; 

//An array containing the current RGB value
int current[3] = {
  0, 0, 0
}; 

//An array containing the new desired RGB value
int desired[3]; 

//An array containing the increment size for each colour
int fadeSize[3]; 


void setup() {
  Serial.begin(9600); 

  //Configures each of the LED pins
  for (int i = 0; i < 3; i++) {
    pinMode(pins[i], OUTPUT); 
    digitalWrite(pins[i], LOW); 
  }
}


void loop() {
  if (Serial.available() > 0) {
    /*  If serial is available, the following code will parse out the integers, and assign them to values the the desired array
    *   First number is red, second is green and third is blue
    *
    *   This step is done before any colours get switched, as it takes a bit of time to perform
    */
    for (int i = 0; 0 < Serial.available(); i++) { 
      int k = Serial.read(); 
      k = Serial.parseInt(); 
      desired[i] = k; 
    }

    Serial.println("Done Parsing"); //Feedback to the user
    delay(500); 
  }

  /*  The following code will first check if any changes have occured in the desired array
  *   If there has, it will first calculate the fadeSize of each colour, by splitting the difference in value over the amount of fade steps
  *
  *   When that is completed, the code will the loop for the amount of times determined by 'fadeSteps'
  *   Within each of these loops, it will cycle through each of the colours, changing its value by the current and the fade size 
  * 
  *   Upon completetion, updates the current values to the desired ones, and updates the LED colour, incase a slight mismatch has occured due to rounding errors
  */
  if (current[0] != desired[0] || current[1] != desired[1] || current[2] != desired[2]) {
    for (int i = 0; i < 3; i++) {
        fadeSize[i] = ((current[i] - desired[i]) / fadeSteps);  
      }
    for (int i = 0; i < fadeSteps; i++) {
      for (int j = 0; j < 3; j++) { 
        analogWrite(pins[j], (current[j] - (fadeSize[j] * (i + 1))));
      }
      
      Serial.println("Fade step " + String(i + 1) + " complete!"); //Feedback for the user
      delay(fadeTime / fadeSteps); //Delay ensuring a desired fade duration is achieved
    }

    for (int i = 0; i < 3; i++) {
      current[i] = desired[i]; 
      analogWrite(pins[i], current[i]); 
    }
  }
}
