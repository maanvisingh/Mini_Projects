# Mini Projects
This repository is used for documenting the codes for some of the Mini Projects that I have done. Most of which are just prototypes.
1. [LCD Game](https://github.com/maanvisingh/Mini_Projects/edit/main/README.md#lcd-game)
2. [Pick and Place Bot](https://github.com/maanvisingh/Mini_Projects/edit/main/README.md#pick-and-place-bot)
3. [3 DOF Arm](https://github.com/maanvisingh/Mini_Projects/edit/main/README.md#3-dof-arm)
4. [Stewart Platform](https://github.com/maanvisingh/Mini_Projects/edit/main/README.md#stewart-platform)
5. [String Art](https://github.com/maanvisingh/Mini_Projects/edit/main/README.md#string-art)

## LCD Game 
This is an endless runner video game simulated on an LCD. The character in the game has to avoid all the obstacles coming it's way to stay alive and the score is based on the time for which the character is alive. 

### Components 
- 1602A LCD Module 
- Arduino UNO
- Push Button 
- Potentiometer 
- Breadboard 
- Jumper Wires

### Arduino Code and Circuit
- [Code](https://github.com/maanvisingh/Mini_Projects/blob/main/LCD%20_Game/LCD_Game.ino)
- [Circuit](https://github.com/maanvisingh/Mini_Projects/blob/main/LCD%20_Game/LCD_Game.png)
- [Reference Video](https://github.com/maanvisingh/Mini_Projects/blob/main/LCD%20_Game/lcd_game_video.mp4)

## Pick and Place Bot
This bot is a Line Following Robot with a gripper fixed to it, that is used to autonomously transport boxes from one place to the other. The bot works on a 4-wheeled holonomic drive.

Task: 
- Starts at location A.
- Follows a line, using lsa values, to the destination location B where the boxes to be transported are placed.
- Based on the ultrasonic sensor value, actuates the gripper to pick up the object.
- Follows the line back to location A.
- Opens the gripper and drops the object at loction A.
- Repeats the task until all boxes are transported.

### Components 
- 4 Omni Wheels 
- 2 MDD 10A Motor Drivers
- 12V Battery 
- LSA08 
- Ultrasonic Sensor
- Arduino UNO
- Jumper Wires

### Arduino Code
- [Holonomic Drive and Line Following Bot](https://github.com/maanvisingh/Mini_Projects/blob/main/Pick_place_bot/4-wheel_pickPlace.ino)

## 3 DOF Arm
It is a 3 degrees of freedom arm which uses 3 servo motors for each of the three revolute joints. The initial motivation behind this project is to learn the forward and inverse kinematics of arm manipulators and implement it on this model.

### Components
- Arduino UNO
- 3 SG90 Servo Motors 
- 3D printed parts
- Jumper Wires 
- Power Distribution Board 
- 12V Battery

### Arduino Code
- [Test Code](https://github.com/maanvisingh/Mini_Projects/blob/main/3_DOF/ps2_3dof.ino)
- [Test Video](https://github.com/maanvisingh/Mini_Projects/blob/main/3_DOF/3dof.mp4)

## Stewart Platform 
This Stewart platform is parallel manipulator that has six revolute joints instead of the usual prismatic joints to reduce the built complexity. These revolute joints are actuated using 6 SG90 Servo Motors. The initial motivation behind this is to learn the kinematics for the stewart platform and implement it on this model.

### Compnents 
- Arduino UNO
- 6 SG90 Servo Motors 
- 3D printed parts
- Jumper Wires 
- Power Distribution Board 
- 12V Battery

### Arduino Code 
- [Test Video 1](https://github.com/maanvisingh/Mini_Projects/blob/main/Stewart_Platform/test1.mp4)
- [Test Video 2](https://github.com/maanvisingh/Mini_Projects/blob/main/Stewart_Platform/test2.mp4)
- [Test Code](https://github.com/maanvisingh/Mini_Projects/blob/main/Stewart_Platform/Stewart.ino)

### String Art
Building a machine to automate the process of nail art. 

- [Reference Research Paper](https://www.researchgate.net/publication/322766118_String_Art_Towards_Computational_Fabrication_of_String_Images)
- [Test Code](https://github.com/maanvisingh/Mini_Projects/blob/main/String_Art/array_stepper/array_stepper.ino)
 

