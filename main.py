def main():
    from keyboard_controller import KeyboardController
    import serial
    from gamepad_controller import GamePadController
    import threading

    arduino = serial.Serial(port='COM4', baudrate=115200, timeout=.1)


    keyboard_thread = threading.Thread(target=KeyboardController,args=(arduino,))
    gamepad_thread = threading.Thread(target=GamePadController,args=(arduino,))

    keyboard_thread.start()
    gamepad_thread.start()

    keyboard_thread.join()
    gamepad_thread.join()

    arduino.close()
    

main()