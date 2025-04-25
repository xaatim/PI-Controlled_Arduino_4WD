import serial
import time

arduino = serial.Serial(port='COM4',   baudrate=115200, timeout=.1)

def controller(keys:str):
    arduino.write(bytes(keys,   'utf-8'))
    time.sleep(0.05)
    
    
try:
    while True:
        keys = input("Enter a number: ")
        controller(keys)
        result = arduino.readline()
        print(result)
        
except:
    KeyboardInterrupt
    arduino.write(bytes('q',   'utf-8'))
