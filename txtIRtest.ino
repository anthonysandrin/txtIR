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

IRsend irsend;

void test() {
  Serial.println("NEC tests");
  digitalWrite(13, HIGH); 
  irsend.sendNEC(0x20DF10EF , 32);
  delay(10000);
  
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
