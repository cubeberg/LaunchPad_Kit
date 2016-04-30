/*
 Module: Grove Relay 
 http://www.seeedstudio.com/depot/Grove-Relay-p-769.html
 
 Description:
 Basic Relay example. Turns relay on for one second, the off for a second, repeatedly.  
 
 The circuit:
 * Grove Relay attached to the J14 plug on Grove Base BoosterPack (Pin 39)
 
 This example code is in the public domain.
*/

// Let's use #define to rename our pins from numbers to readable variables
// This is good practice when writing code so it is less confusing to read
#define RELAY_PIN 39

/* the setup() method runs once, when the sketch starts */
void setup() { 
  /* Set the relay pin as output so we can use it to turn the relay off and on */
  pinMode(RELAY_PIN, OUTPUT);  
}

/* the loop() method runs over and over again */
void loop() {
  // turn the relay on (HIGH is the voltage level)
  digitalWrite(RELAY_PIN, HIGH); 
  // wait for a second
  delay(1000);   
  // turn the relay off by making the voltage LOW
  digitalWrite(RELAY_PIN, LOW);   
  // wait for a second
  delay(1000);   
}
