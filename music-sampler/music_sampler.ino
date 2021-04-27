#include <Keypad.h>
#include "pitches2.h"

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {10, 9, 8, 7}; 
byte colPins[COLS] = {6, 5, 4, 3};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

int piezoPin = 13;
int notesCnt = 26;
int thisNote = 0;

int melody[] = {
  //NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, NOTE_B3, NOTE_C4
  A, A, NOTE_F, CH, A, NOTE_F, CH, A, EH, EH, EH, FH, CH, GS, NOTE_F, CH, A, NOTE_F, GS, NOTE_F, A, CH, A, CH, EH
  
};

int noteDurations[] = {
  //4, 8, 8, 4, 4, 4, 4
  500, 500, 500, 350, 350, 500, 350, 350, 650, 500, 500, 500, 350, 350, 500, 350, 350, 650, 250, 500, 350, 125, 500, 375, 125, 650
};

void setup(){
  Serial.begin(9600); // DEBUG
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(melody[thisNote]); // DEBUG
    
    //int noteDuration = 1000 / noteDurations[thisNote];
    int noteDuration = noteDurations[thisNote];
    tone(piezoPin, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(piezoPin);

    
    thisNote++;
    
    if (thisNote == notesCnt) {
      thisNote = 0;
    }
    
  }
}
