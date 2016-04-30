/*
 Module: Grove Light Sensor
 http://www.seeedstudio.com/depot/Grove-Light-Sensor-p-746.html
 
 A simple program that display the value of light from the Grove Light Sensor
 on the Grove 4-Digit Display, this example is very similar to the Grove Rotary Angle Sensor example
 
 The circuit:
 * 4-Digit Display - attach to the J14 plug on the Grove Base BoosterPack (Pins 38 and 39) 
 * Light Sensor - attach to the J6 plug on Grove Base BoosterPack (Pin 24)
 
 Created by Oliver Wang
 This example code is in the public domain.
*/

//Include the 4-Digit Display library
#include "TM1637.h" 

// Let's use #define to rename our pins from numbers to readable variables
// This is good practice when writing code so it is less confusing to read
#define CLK               39                  /* 4-Digit Display clock pin */
#define DIO               38                 /* 4-Digit Display data pin */
#define LIGHT_SENSOR      24                 /* pin connected to the Light Sensor */

/* Global Variables */
TM1637 tm1637(CLK, DIO);                  /* 4-Digit Display object */
int analog_value = 0;                     /* variable to store the value coming from Light Sensor */
int8_t bits[4] = {0};                     /* array to store the single digits of the value */

/* the setup() method runs once, when the sketch starts */
void setup() 
{
  /* Initialize 4-Digit Display */
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);
}

/* the loop() method runs over and over again */
void loop() 
{   
  analog_value = analogRead(LIGHT_SENSOR);        /* read the value from the sensor */
  	
  memset(bits, 0, 4);                             /* reset array before we use it */
  for(int i = 3; i >= 0; i--) 
  {
    /* Convert the value to individual decimal digits for display */
    bits[i] = analog_value % 10;
    analog_value = analog_value / 10;  
    tm1637.display(i, bits[i]);                 /* display value on 4-Digit Display */
  }
  delay(100);  //small delay so that the number doesn't change too quickly to read
}
