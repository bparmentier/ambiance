#!/usr/bin/env python

import serial
import sys
from subprocess import call

arduino = serial.Serial('/dev/ttyACM0', 9600)

try:
    while 1:
        output = arduino.readline()
        print output
        if output == 'ON\r\n':
            print 'ON'
            call(['mpc', '-h', '192.168.1.36', 'play'])

        if output == 'OFF\r\n':
            print 'OFF'
            call(['mpc', '-h', '192.168.1.36', 'pause'])

except KeyboardInterrupt:
    print '\nBye.'
    arduino.close()
    sys.exit(0)
