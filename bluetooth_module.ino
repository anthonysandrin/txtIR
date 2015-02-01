#include <SoftwareSerial.h>

int ledPin = 13;
int state = 0;
int bluetoothTx = 5; 
int bluetoohtRx = 4; 

SoftwareSerial bluetooth( bluetoothTx, bluetoothRx);

void setup(){
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
  bluetooth.begin(9600); //Default connection rate for bluetooth module
}

void loop(){
  if(bluetooth.available()>0){
    state = bluetooth.read();
  }
  if (state == 0){
    digitalWrite(ledPin, LOW);
  }
  else if(state == 1){
    digitalWrite(ledPin, HIGH);
  }
}
