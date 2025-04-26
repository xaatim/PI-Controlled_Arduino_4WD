import keyboard
#arduino = serial.Serial(port='COM4', baudrate=115200, timeout=.1)
def KeyboardController(arduino):
    def on_key_event(e):
        if e.event_type == keyboard.KEY_DOWN:
            if e.name == 'w':
                arduino.write(bytes('f',   'utf-8'))
                print("Forward")
            elif e.name == 's':
                arduino.write(bytes('b',   'utf-8'))
                print("Backward")
            elif e.name == 'a': 
                arduino.write(bytes('r',   'utf-8'))
                print("Right")
            elif e.name == 'd':
                arduino.write(bytes('l',   'utf-8'))
                print("Left")
                return False 
        elif e.event_type == keyboard.KEY_UP:
            arduino.write(b'q')  

    print("Use arrow keys to control. Press 'q' to quit.")
    keyboard.hook(on_key_event)
    keyboard.wait('Esc')  
