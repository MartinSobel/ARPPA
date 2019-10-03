// En Ableton arranca en C1

#include "MIDIUSB.h"

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void setup() {
  Serial.begin(115200);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  midiEventPacket_t rx;
  do {
    rx = MidiUSB.read();
    if (rx.header != 0) {
/*
      LEEDOR
      Serial.print(rx.byte2);  
      Serial.print(" - ");
      Serial.print(rx.header);
      Serial.println();
*/
      //HACER LO MISMO 
      if (rx.byte2 == 36){
        if (rx.header == 8){
            digitalWrite(0, HIGH); 
        }
        if (rx.header == 9){
            digitalWrite(0, LOW);
        }
      }
      
      if (rx.byte2 == 37){
        if (rx.header == 8){
            digitalWrite(1, HIGH); 
        }
        if (rx.header == 9){
            digitalWrite(1, LOW);
        }
      }

      if (rx.byte2 == 38){
        if (rx.header == 8){
            digitalWrite(2, HIGH); 
        }
        if (rx.header == 9){
              digitalWrite(2, LOW);
        }
      }

      if (rx.byte2 == 39){
        if (rx.header == 8){
            digitalWrite(3, HIGH); 
        }
        if (rx.header == 9){
            digitalWrite(3, LOW);
        }
      }

    }
  } while (rx.header != 0);
}
