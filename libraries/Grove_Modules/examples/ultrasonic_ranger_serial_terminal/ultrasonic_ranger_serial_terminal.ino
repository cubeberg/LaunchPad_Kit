/*
 Module: Ultrasonic-Ranger
 http://www.seeedstudio.com/depot/Grove-Ultrasonic-Ranger-p-960.html
 
 Description:
 Measure the distance to obstacles in front and print the distance
 value to the serial monitor.
 
 The circuit:
 * Ultrasonic Ranger attached to the J6 plug on Grove Base BoosterPack (Pin 24)
 
 Note:
 Set the serial monitor to 9600 baud
 
 Written by FrankieChu for Seeed Studio
 
 This example code is in the public domain.
 */

//Ultrasonic sensor library
#include "Ultrasonic.h"

// Let's use #define to rename our pins from numbers to readable variables
// This is good practice when writing code so it is less confusing to read
#define ULTRASONIC_PIN    24              /* pin of the Ultrasonic Ranger */

/* Global Variables */
Ultrasonic ultrasonic(ULTRASONIC_PIN);

/* the setup() method runs once, when the sketch starts */
void setup()
{
  /* Initialize Serial port at 9600 baud */
  Serial.begin(9600);
}

/* the loop() method runs over and over again */
void loop()
{
  long RangeInInches;
  long RangeInCentimeters;
  RangeInInches = ultrasonic.MeasureInInches();              /* read the value from the sensor */
  RangeInCentimeters = ultrasonic.MeasureInCentimeters();    /* read the value from the sensor */
  
  /* Send value to the Serial Monitor */
  Serial.println("The distance to obstacles in front is: ");
  Serial.print(RangeInInches);//0~157 inches
  Serial.println(" inch");
  Serial.print(RangeInCentimeters);//0~400cm
  Serial.println(" cm");
  
  //Slight delay between readings
  delay(100);
}
