/*
simple LED test
*/

#include <IRremote.h>

IRsend irsend;

int ledpin = 2;  // LED connected to pin 2 (on-board LED)

void setup()
{
  pinMode(ledpin = 13, OUTPUT);  // pin 13 (on-board LED) as OUTPUT

  Serial.begin(9600);       // start serial communication at 115200bps

}

void sendn(int code, int count) {
  for(int i = 0; i < count; i++) {
    digitalWrite(13, HIGH);
    irsend.sendNEC(code, 32);
    delay(100);
    digitalWrite(13, LOW);
    delay(150);
  }
}

void loop() {
  char val;
  int n;
  if(Serial.available())
  {
    val = Serial.read();
    n = Serial.parseInt();
  }
  
  if( val == 'p') {
    Serial.println("NEC Power");
    sendn(0x20DF10EF, n);
  } else if( val == 'i') {
    Serial.println("NEC Input");
    sendn(0x20DFD02F, n);
  } else if( val == 'm') {
    Serial.println("NEC Mute");
    sendn(0x20DF906F, n);
  } else if( val == 'o') {
    Serial.println("NEC OK");
    sendn(0x20DF22DD, n);
  } else if (val == 'l') {
    Serial.println("NEC Volume Down");
    sendn(0x20DFC03F, n);
  } else if (val == 'r') {
    Serial.println("NEC Volume Up");
    sendn(0x20DF40BF, n);
  }
  delay(500);
}
