import sys,os
import serial
import serial.tools.list_ports

ser = serial.Serial()
ser.baudrate = 9600
for file in os.listdir('/dev'):
    if "tty.usbmodem" in file:
        ser.port = '/dev/'+file
        ser.open()

while True:
    sys.stdout.write(ser.readline())

ser.close()
