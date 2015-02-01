import urllib2
import time

import serial
ser = serial.Serial('/dev/tty.usbmodem1411', 9600)

def onmessage(message):
    if "power" in message:
        print("sending power")
        ser.write('p')
	ser.write(str(1))
    elif "input" in message:
	print("sending input")
        ser.write('i')
	ser.write(str(1))
    elif "mute" in message:
	print("sending mute")
        ser.write('m')
	ser.write(str(1))
    elif "down" in message:
	print("sending volume down")
        ser.write('l')
	ser.write(str(5))
    elif "up" in message:
	print("sending volume up")
        ser.write('r')
	ser.write(str(5))

while True:
    time.sleep(2.5)
    try:
        messages = urllib2.urlopen("http://sandrin.me:1042").read()
        if len(messages) > 0:
            for message in messages.splitlines():
                print("got message")
                onmessage(message.lower())
    except Exception:
	print("error")

