# Mini Projects
This repository is used for documenting the codes for some of the Mini Projects that I have done. Most of which are just prototypes.
1. [LCD Game](https://github.com/maanvisingh/Mini_Projects/edit/main/README.md#lcd-game)
2. [Pick and Place Bot](https://github.com/maanvisingh/Mini_Projects/edit/main/README.md#pick-and-place-bot)
3. [3 DOF Arm](https://github.com/maanvisingh/Mini_Projects/edit/main/README.md#3-dof-arm)
4. [Stewart Platform](https://github.com/maanvisingh/Mini_Projects/edit/main/README.md#stewart-platform)

## LCD Game 
This is an endless runner video game simulated on an LCD. The character in the game has to avoid all the obstacles coming it's way to stay alive and the score is based on the time for which the character is alive. 
- [Reference]

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
- [Reference]
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

## 3 DOF Arm
It is a 3 degrees of freedom arm which uses 3 servo motors for each of the three revolute joints. The initial motivation behind this project is to learn the forward and inverse kinematics of arm manipulators and implement it on this model.
- [Reference]

### Components
- Arduino UNO
- 3 SG90 Servo Motors 
- 3D printed parts
- Jumper Wires 
- Power Distribution Board 
- 12V Battery

### Kinematics
Still working on it.

## Stewart Platform 
This Stewart platform is parallel manipulator that has six revolute joints instead of the usual prismatic joints to reduce the built complexity. These revolute joints are actuated using 6 SG90 Servo Motors. The initial motivation behind this is to learn the kinematics for the stewart platform and implement it on this model.
- [Reference]

### Compnents 
- Arduino UNO
- 6 SG90 Servo Motors 
- 3D printed parts
- Jumper Wires 
- Power Distribution Board 
- 12V Battery

### Kinematics 
Still working on it.

 

