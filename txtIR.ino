/*
 * IRremote: IRtest unittest
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 *
 * Note: to run these tests, edit IRremote/IRremote.h to add "#define TEST"
 * You must then recompile the library by removing IRremote.o and restarting
 * the arduino IDE.
 */

#include <IRremote.h>
#include <IRremoteInt.h>

#define PanasonicAddress      0x4004     // Panasonic address (Pre data) 
#define PanasonicPower        0x100BCBD  // Panasonic Power button

IRsend irsend;

void test() {
  Serial.println("NEC tests");
  digitalWrite(13, HIGH); 
  irsend.sendNEC(0x20DF10EF , 32);
  delay(1000);
  
  Serial.println("Sony tests");
  digitalWrite(13, LOW); 
  for (int i = 0; i < 3; i++) {
      irsend.sendSony(0xa90, 12); // Sony TV power code
      delay(40);
  }
  delay(1000);
  
  Serial.println("RC5 tests");
  digitalWrite(13, HIGH); 
  //testRC5(0xfff, 12);
  delay(1000);
  
  Serial.println("RC6 tests");
  digitalWrite(13, LOW); 
  irsend.sendRC6(0x2000, 20);
  delay(1000);
  
  Serial.println("Panasonic");
  digitalWrite(13, HIGH); 
  irsend.sendPanasonic(PanasonicAddress,PanasonicPower); // This should turn your TV on and off
  delay(1000);
  
  Serial.println("JVC");
  digitalWrite(13, LOW); 
  irsend.sendJVC(0xC5E8, 16,0); // hex value, 16 bits, no repeat
  delayMicroseconds(50); // see http://www.sbprojects.com/knowledge/ir/jvc.php for information
  irsend.sendJVC(0xC5E8, 16,1); // hex value, 16 bits, repeat
  delayMicroseconds(50);
  delay(1000);
}

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  
  test();
}

void loop() {
  test();
}
