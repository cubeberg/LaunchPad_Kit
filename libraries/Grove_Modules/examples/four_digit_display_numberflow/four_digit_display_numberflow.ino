/*
 Module: 4-Digit Display
 http://www.seeedstudio.com/depot/Grove-4Digit-Display-p-1198.html

 Description: 
 Display numbers, in hex, from 0-15, on the 4-Digit Display
 
 The circuit:
 * 4-Digit Display attached to the J14 plug on Grove Base BoosterPack (Pins 38 and 39)
 
 Written by Frankie Chu for Seeed Studio 

 This example code is in the public domain.
 */

//4-Digit Display library
#include "TM1637.h"

// Let's use #define to rename our pins from numbers to readable variables
// This is good practice when writing code so it is less confusing to read
#define CLK               39              /* 4-Digit Display clock pin */
#define DIO               38              /* 4-Digit Display data pin */

/* Global Variables */
TM1637 tm1637(CLK, DIO);                  /* 4-Digit Display object */;
int8_t NumTab[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};//0~9,A,b,C,d,E,F
int8_t ListDisp[4];
unsigned char i = 0;
unsigned char count = 0;

/* the setup() method runs once, when the sketch starts */
void setup()
{
  /* Initialize 4-Digit Display */
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

/* the loop() method runs over and over again */
void loop()
{
  i = count;
  count ++;
  //start numbers over again when we hit the end
  if(count == sizeof(NumTab)) 
    count = 0;
   
  //Prepare 4 numbers to show on the display
  for(unsigned char BitSelect = 0;BitSelect < 4;BitSelect ++)
  {
    ListDisp[BitSelect] = NumTab[i];
    i ++;
    if(i == sizeof(NumTab)) i = 0;
  }
  
  //Update the display
  tm1637.display(0,ListDisp[0]);
  tm1637.display(1,ListDisp[1]);
  tm1637.display(2,ListDisp[2]);
  tm1637.display(3,ListDisp[3]);
  
  //Delay before next update
  delay(300);
}
