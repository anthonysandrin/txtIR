import urllib2
import time

while True:
    time.sleep(5)
    try:
        messages = urllib2.urlopen("http://sandrin.me:1042").read()
        if len(messages) > 0:
            for message in messages.splitlines():
                print(message)
    except Exception:
        print("Can't connect")
