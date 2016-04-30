/*
 Module: Grove Sound Sensor
 http://www.seeedstudio.com/depot/Grove-Sound-Sensor-p-752.html
 
 A simple program demonstrating sound detection.  When sound is detected over the set threshold,
 the LED is turned on for 1 second.
 
 The circuit:
 * Sound Sensor attached to the J6 plug on Grove Base BoosterPack (Pin 24)
 
 This example code is in the public domain.
 */

// Let's use #define to rename our pins from numbers to readable variables
// This is good practice when writing code so it is less confusing to read 
#define SOUND_SENSOR       24           /* sound sensor pin */          
#define LED                RED_LED      /* LED pin */
#define THRESHOLD_VALUE    200          /* The threshold to turn the LED on 200.00*3.3/1024 = 0.65v */

/* Global Variables */
int sound_value = 0;       /* variable to store the value coming from sound sensor */

/* the setup() method runs once, when the sketch starts */
void setup() 
{
    /* Initialize LED pin */
    pinMode(LED, OUTPUT);  
    /* Turn LED off */
    digitalWrite(LED, LOW); 
}
 
/* the loop() method runs over and over again */
void loop() 
{
    /* read the Sound Sensor value */
    sound_value = analogRead(SOUND_SENSOR); 
	
    /* if the sensor value is higher than threshold, turn on LED */
    if(sound_value > THRESHOLD_VALUE) 
    {
        digitalWrite(LED, HIGH); 
        delay(1000);
    }
    /* Turn LED off */
    digitalWrite(LED, LOW);
}

 
