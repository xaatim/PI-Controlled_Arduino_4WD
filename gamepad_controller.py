import pygame
import time



def GamePadController(arduino):
    pygame.init()
    pygame.joystick.init()
    def send_command(command):
        arduino.write(bytes(command, 'utf-8'))
        print(f"Command sent: {command}")

    if pygame.joystick.get_count() > 0:
        joystick = pygame.joystick.Joystick(0)
        joystick.init()
        print(f"Joystick detected: {joystick.get_name()}")
    else:
        print("No joystick detected")
        exit()  
        
        
    last_command = None
    last_send_time = time.time()

    dead_zone = 0.5
    while True:
    
        for event in pygame.event.get():
            if event.type == pygame.JOYAXISMOTION:
            
                axis_x = joystick.get_axis(0) 
                axis_y = joystick.get_axis(1)  
                current_command = None
                
                if axis_y < -dead_zone:
                    current_command = 'f'  # Forward
                elif axis_y > dead_zone:
                    current_command = 'b'  # Backward
                elif axis_x < -dead_zone:
                    current_command = 'l'  # Left
                elif axis_x > dead_zone:
                    current_command = 'r'  # Right
                else:
                    current_command = 'q'  # Stop

                
                if current_command != last_command or time.time() - last_send_time > 0.1:
                    send_command(current_command)
                    last_command = current_command
                    last_send_time = time.time()
            if event.type == pygame.QUIT:
                pygame.quit()
                arduino.close()
                exit()
        pygame.time.wait(10)
