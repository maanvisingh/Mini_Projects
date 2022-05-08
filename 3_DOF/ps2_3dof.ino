#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
#include <Servo.h>

Servo myservo;
Servo myservo1;
Servo myservo2;
int pos = 0;

Cytron_PS2Shield ps2(2, 3); // SoftwareSerial: Rx and Tx pin
//Cytron_PS2Shield ps2; // HardwareSerial

void setup()
{
  ps2.begin(9600); // This baudrate must same with the jumper setting at PS2 shield
  Serial.begin(9600);
  myservo.attach(8);
  myservo1.attach(9);
  myservo2.attach(10);
}

void loop()
{
  if (ps2.readButton(PS2_CROSS) == 0) //Home Position
  {
    myservo.write(35);
    delay(1000);
    myservo1.write(90);
    delay(1000);
    myservo2.write(110);
    delay(1000);

    Serial.println("Cross is pressed");
  }

  if (ps2.readButton(PS2_LEFT) == 0) //Home Position
  {
    myservo.write(100);
    delay(1000);
    myservo1.write(50);
    delay(1000);
    myservo2.write(40);
    delay(1000);
  }

  if (ps2.readButton(PS2_RIGHT) == 0) //Home Position
  {
    myservo.write(10);
    delay(1000);
    myservo1.write(50);
    delay(1000);
    myservo2.write(40);
    delay(1000);

  }
}
