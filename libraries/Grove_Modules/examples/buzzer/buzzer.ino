/*
 Module: Grove Buzzer
 http://www.seeedstudio.com/depot/Grove-Buzzer-p-768.html

 Description:
 The example uses a buzzer to play melodies. It sends a square wave of the 
 appropriate frequency to the buzzer, generating the corresponding tone.
 
 The circuit:
 * Buzzer - attach to the J14 plug on Grove Base BoosterPack (Pin 39)

 This example code is in the public domain.
*/

// Let's use #define to rename our pins from numbers to readable variables
// This is good practice when writing code so it is less confusing to read
#define BUZZER_PIN               39            /* sig pin of the Grove Buzzer attached to J14 on the Grove BoosterPack */

/* Global Variables */
int length = 15;         // the number of notes in the song
char notes[] = "ccggaagffeeddc "; //notes in the song
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 }; //length of each note
int tempo = 200;  //speed of the song

/* the setup() method runs once, when the sketch starts */
void setup()
{
  /* set buzzer pin as output so we can use it to turn the buzzer off and on */
  pinMode(BUZZER_PIN, OUTPUT);       
}

/* the loop() method runs over and over again */
void loop()
{
  //Loop through each note
  for(int i = 0; i < length; i++) 
  {
    //space indicates a pause
    if(notes[i] == ' ') 
    {
      delay(beats[i] * tempo);
    } 
    else  //Otherwise, we play the note
    {
      playNote(notes[i], beats[i] * tempo);
    }
    delay(tempo / 2);    /* delay between notes */
  }
}

/* Figures out what Tone to play for the specified Note */
void playNote(char note, int duration) 
{
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) 
  {
    if (names[i] == note) 
    {
      playTone(tones[i], duration);
    }
  }
}

char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

/* generates a square wave to play a specific Tone by turning the buzzer off and on at a specific speed */
void playTone(int tone, int duration) 
{
  for (long i = 0; i < duration * 1000L; i += tone * 2) 
  {
    digitalWrite(BUZZER_PIN, HIGH); //Buzzer on
    delayMicroseconds(tone);
    digitalWrite(BUZZER_PIN, LOW);  //Buzzer off
    delayMicroseconds(tone);
  }
}
