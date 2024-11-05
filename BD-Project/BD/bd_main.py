import random
import math
from playsound import playsound
import time
from time import *
from adafruit_servokit import ServoKit
import board
import neopixel

kit = ServoKit(channels=16)
#the use case for a playsound is to call playsound("[name of soundfile with extension]")
# MAKE SURE TO USE THESE COMMANDS THROUGH TERMINAL FIRST FOR NEOPIXELS 
# sudo pip3 install rpi_ws281x adafruit-circuitpython-neopixel
# sudo python3 -m pip install --force-reinstall adafruit-blinka

def main():
    # NeoPixels must be connected to D10, D12, D18 or D21 to work.
    head_array = neopixel.NeoPixel(board.D10, 30)
    accent_lights = neopixel.NeoPixel(board.D12 ,3)

    motor1 = kit.servo[0]
    motor2 = kit.servo[1]
    motor3 = kit.servo[2]
    motor4 = kit.servo[3]
    modes = ["idle", "alert", "looking around", "scanning", "displaying"]
    #set different color values
    off = [0,0,0]
    white = [255,255,255]
    red = [255,0,0]
    green = [75,255,0]
    yellow = [220,255,0]
    blue = [0,230,255]

    #instantiate position and lights 
    motor1.angle(90)
    motor2.angle(0)
    motor3.angle(0)
    motor4.angle(90)
    current_color = blue
    head_array.fill(blue)
    accent_lights[0] = off
    accent_lights[1] = green
    accent_lights[2] = off
    mode=modes[0]

    #the following contains code that bakes animations and runs them on a real-time clock.
    #Putting the animation on a frame-by-frame basis makes it possible to control the timing of actions,
    #as well as to calculate multiple things happening "at once" to the human eye.
    while True:

        #The idle animation sets the ears to default position, and then, will continually move the eye back and forth.
        if mode=="idle":
            motor_inc2 = motor_control_increments(90,motor2.read())
            motor_inc4 = motor_control_increments(0,motor4.read())
            color_inc = fade_color_increments(current_color, blue)

            playsound("sounds/chirp2.wav")
            for frames in range(0,1000):
                frame_data(motor1,motor2,motor3,motor4,head_array,current_color,0,motor_inc2,motor_inc2,0,color_inc)
                time.sleep(1)
            current_color = blue
            for back_and_forth in range(0,2):
                time.sleep(random(0,2000))
                for frames in range(0,1000):
                    frame_data(motor1,motor2,motor3,motor4,head_array,current_color,0,0,0,motor_inc4)
                    time.sleep(1)
                motor_inc4 = 0-motor_inc4
            motor_inc4 = 0-motor_inc4  

        #In the alert mode, an animation is baked in which the droids head will turn left, followed by his eye,
        #then, turn right, followed by the eye. After which, the head and eye are set to the center.
        #visually, it looks like a minecraft mob turning, where they turn the head, and the body follows.
        elif mode=="alert":
            #set position to mid-left, move by frame
            motor_inc1 = motor_control_increments(45,motor1.read())
            motor_inc4 = motor_control_increments(45,motor4.read())
            color_inc = fade_color_increments(current_color,yellow, 500)
            playsound("sounds/trill2.wav")
            for frames in range(0,500):
                frame_data(motor1,motor2,motor3,motor4,head_array,current_color,motor_inc1,0,0,0,color_inc)
            current_color = yellow

            accent_lights[2] = yellow
            time.sleep(100)
            accent_lights[2] = off
            for frames in range(0,500):
                frame_data(motor1,motor2,motor3,motor4,head_array,current_color,0,0,0,motor_inc4)
            accent_lights[2] = yellow
            time.sleep(100)
            accent_lights[2] = off
            #set position to mid-right, move by frame
            motor_inc1 = motor_control_increments(135,motor1.read())
            motor_inc4 = motor_control_increments(135,motor4.read())
            for frames in range(0,500):
                frame_data(motor1,motor2,motor3,motor4,head_array,current_color,motor_inc1,0,0,0)
            accent_lights[2] = yellow
            time.sleep(100)
            accent_lights[2] = off
            for frames in range(0,500):
                frame_data(motor1,motor2,motor3,motor4,head_array,current_color,0,0,0,motor_inc4)
            accent_lights[2] = yellow
            time.sleep(100)
            accent_lights[2] = off
            #set position to center, move by frame
            motor_inc1 = motor_control_increments(90,motor1.read())
            motor_inc4 = motor_control_increments(90,motor4.read())
            for frames in range(0,500):
                frame_data(motor1,motor2,motor3,motor4,head_array,current_color,motor_inc1,0,0,0)
            accent_lights[2] = yellow
            time.sleep(100)
            accent_lights[2] = off
            for frames in range(0,500):
                frame_data(motor1,motor2,motor3,motor4,head_array,current_color,0,0,0,motor_inc4)
            accent_lights[2] = yellow
            time.sleep(100)
            accent_lights[2] = off
            
        #In the scanning mode, the different body parts are reset to their original position, and the eye
        #will turn on, and play a corresponding sound. after about a tenth of a second, the light changes colors 
        #from blue to red, and continues the animation.
        elif mode=="scanning": 
            #set default position of all moving parts
            motor_inc1 = motor_control_increments(90,motor1.read())
            motor_inc2 = motor_control_increments(45,motor2.read())
            motor_inc3 = motor_control_increments(45,motor3.read())
            motor_inc4 = motor_control_increments(90,motor4.read())
            color_inc = fade_color_increments(current_color, green)

            for frames in range(0,1000):
                frame_data(motor1,motor2,motor3,motor4,head_array,current_color,motor_inc1,motor_inc2,motor_inc3,motor_inc4,color_inc)
            accent_lights[0]=blue
            playsound("sounds/scan.wav")
            time.sleep(100)
            accent_lights[0]=red
            playsound("sounds/scan.wav")
            time.sleep(800)
            accent_lights[0]=off

        
        #Looking around is similar to idle, but without the indicator led blinking, and plays different voice sounds.
        elif mode=="looking around":
            #set position to mid-left, move by frame
            motor_inc1 = motor_control_increments(45,motor1.read())
            motor_inc4 = motor_control_increments(45,motor4.read())
            color_inc = fade_color_increments(current_color,green, 500)
            playsound("sounds/chirp.wav")
            for frames in range(0,500):
                frame_data(motor1,motor2,motor3,motor4,head_array,current_color,motor_inc1,0,0,0,color_inc)
            current_color = yellow

            for frames in range(0,500):
                frame_data(motor1,motor2,motor3,motor4,head_array,current_color,0,0,0,motor_inc4)
            #set position to mid-right, move by frame
            motor_inc1 = motor_control_increments(135,motor1.read())
            motor_inc4 = motor_control_increments(135,motor4.read())
            for frames in range(0,500):
                frame_data(motor1,motor2,motor3,motor4,head_array,current_color,motor_inc1,0,0,0)
            for frames in range(0,500):
                frame_data(motor1,motor2,motor3,motor4,head_array,current_color,0,0,0,motor_inc4)
            #set position to center, move by frame
            motor_inc1 = motor_control_increments(90,motor1.read())
            motor_inc4 = motor_control_increments(90,motor4.read())
            for frames in range(0,500):
                frame_data(motor1,motor2,motor3,motor4,head_array,current_color,motor_inc1,0,0,0)
            for frames in range(0,500):
                frame_data(motor1,motor2,motor3,motor4,head_array,current_color,0,0,0,motor_inc4)
        
        #the displaying mode turns on the eye color to blue, resets to the default position, and plays audio to correspond
        #with the eye being on. After the audio finishes, the light turns off.
        elif mode=="displaying":    
            motor_inc1 = motor_control_increments(90,motor1.read())
            motor_inc2 = motor_control_increments(45,motor2.read())
            motor_inc3 = motor_control_increments(45,motor3.read())
            motor_inc4 = motor_control_increments(90,motor4.read())
            color_inc = fade_color_increments(current_color, green)

            for frames in range(0,1000):
                frame_data(motor1,motor2,motor3,motor4,head_array,current_color,motor_inc1,motor_inc2,motor_inc3,motor_inc4,color_inc)
            accent_lights[0]=blue
            playsound("sounds/message1.wav")
            time.sleep(2000)
            accent_lights[0]=off
            

#def behavior(mode, pixel1, pixel2, pixel3, shade, currentColor):
    ##emotions should control led color
    #if mode=="idle" and shade:
    #    fade_color(currentColor,blue,pixel1)
    #    pixel3[0] = white
    #elif mode=="idle":
    #    fade_color(currentColor,green,pixel1)
    #if mode=="alert":
    #    fade_color(currentColor,yellow,pixel1)
    #if mode=="looking around":
    ##head should move let and right, looking around.
    ## if a face is identified, follow that face until out of visibility, then snap back
    #if mode=="displaying":
    #    pixel3 = blue
    #    playsound(f"message{random(1,3)}.wav")
    #    time.sleep(1000)
    #    pixel3 = off
    #if mode=="scanning":
    #    pixel3 = blue
    #    playsound("scan.wav")
    #    pixel3 = red
    #    time.sleep(500)
    #    playsound("scan_2.wav")
    #    time.sleep(1500)
    #    pixel3 = off


def fade_color_increments(color1, color2, timeS=1000):
    difference_of_colors = color1-color2
    incrementColors = [difference_of_colors[0]/timeS, difference_of_colors[1]/timeS,difference_of_colors[2]/timeS]
    return incrementColors

def motor_control_increments(position, current_position, timeS=1000):
    difference_of_positions = position-current_position
    increment_position_on_frame = difference_of_positions/timeS
    return increment_position_on_frame

def frame_data(motor1, motor2, motor3, motor4, led_strip, current_color, motor_increments_1=0, motor_increments_2=0, motor_increments_3=0,
               motor_increments_4=0, color_increments=[0,0,0]):
    #this should calculate the data of the frame and output a list for the next frame
    motor1.angle(motor1.read()+motor_increments_1)
    motor2.angle(motor2.read()+motor_increments_2)
    motor3.angle(motor3.read()+motor_increments_3)
    motor4.angle(motor4.read()+motor_increments_4)
    led_strip.fill(current_color+color_increments)

if __name__ == "__main__": 
    main()