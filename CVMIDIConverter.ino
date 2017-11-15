
#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_RingBuffer.h>
#include <midi_Settings.h>

#include <TimerOne.h>
#include <FastPWMdac.h>
int subOscPin = 6;
int cvPin = 9;
int pwmDacVals[] = {51, 54, 57, 61, 64, 68, 72, 81, 86, 91, 97, 102, 108, 115, 122, 129, 137, 145, 153, 162, 172, 182, 193, 205, 217, 230, 243, 258, 273, 289, 307, 325, 344, 365, 386, 409};
//Dac values calculat
int noteFrequencies[] = {33, 35, 37, 39, 41, 44, 46, 49, 52, 55, 58, 62, 65, 69, 73, 78, 82, 87, 93, 98, 104, 110, 117, 123, 131, 139, 147, 156, 165, 175, 185, 196, 208, 220, 233, 247, 262};
                        
//note frequencies for the array are rounded and all the values are found from here http://bit.ly/2hm5oN8
FastPWMdac fastPWMdac;
// Created and binds the MIDI interface to the default hardware Serial port
MIDI_CREATE_DEFAULT_INSTANCE();
void handleNoteOff(byte channel, byte note, byte velocity);
void handleNoteOn(byte channel, byte note, byte velocity);
void setup(){
   fastPWMdac.init(cvPin,8);
   MIDI.begin(1);  // Listen to all incoming messages
   Serial.begin(115200);
   pinMode(subOscPin,OUTPUT);
   pinMode(cvPin,OUTPUT);
   MIDI.setHandleNoteOn(handleNoteOn);
   MIDI.setHandleNoteOff(handleNoteOff);
  
   //initialize array of ints for fastPWMdac analogwritevals.
   //initialize array of ints for 
   
}

void loop(){
    MIDI.read();
}
void handleNoteOn(byte channel, byte note, byte velocity){
  fastPWMdac.analogWrite10bit(pwmDacVals[note-36]);     
  tone(subOscPin,noteFrequencies[note-36]);//turn on note, acts as another oscillator.
  
}
void handleNoteOff(byte channel, byte note, byte velocity){
     noTone(subOscPin); 
}
