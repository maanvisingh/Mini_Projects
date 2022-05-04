# Mini Projects
This repository is used for documenting the codes for some of the Mini Projects that I have done. Most of which are just low budget prototypes.

## Stewart Platform 
This Stewart platform is parallel manipulator that has six revolute joints instead of the usual prismatic joints to reduce the built complexity. These revolute joints are actuated using 6 SG90 Servo Motors. The initial motivation behind this is to learn the kinematics for the stewart platform and implement it on this model.

### Arduino Code 

### Compnents 
- Arduino UNO
- 6 SG90 Servo Motors 

## 3 DOF Arm


### Arduino Code 

### Components
- Arduino UNO
- 3 SG90 Servo Motors 

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
- [Code](https://github.com/maanvisingh/Mini_Projects/blob/main/LCD_Game.ino)
- [Circuit](https://github.com/maanvisingh/Mini_Projects/blob/main/LCD_Game.png)

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
- [Holonomic Drive and Line Following Bot](https://github.com/maanvisingh/Mini_Projects/blob/main/4-wheel_pickPlace/4-wheel_pickPlace.ino)
