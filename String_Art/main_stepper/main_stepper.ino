
#define dirPin 2
#define stepPin 3
int stepsPerRevolution;
int dir;
String input;
String steps;

char gutter;

void flushSerial() 
{
  while (Serial.available())
    gutter = Serial.read();
}

void setup()
{
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Enter the direction (0 or 1) and steps [to be seperated by space]");
  while (Serial.available() == 0)
  {

  }
  dir = Serial.parseInt();
  stepsPerRevolution = Serial.parseInt();
  Serial.println(dir);
  Serial.println(stepsPerRevolution);

  digitalWrite(dirPin, dir);
  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  delay(1000);
  flushSerial();
}




// Define stepper motor connections and steps per revolution:
//#define dirPin 2
//#define stepPin 3
//#define stepsPerRevolution 200
//
//void setup() {
//  // Declare pins as output:
//  pinMode(stepPin, OUTPUT);
//  pinMode(dirPin, OUTPUT);
//}
//
//void loop() {
//  // Set the spinning direction clockwise:
//  digitalWrite(dirPin, HIGH);
//
//  // Spin the stepper motor 1 revolution slowly:
//  for (int i = 0; i < stepsPerRevolution; i++) {
//    // These four lines result in 1 step:
//    digitalWrite(stepPin, HIGH);
//    delayMicroseconds(1000);
//    digitalWrite(stepPin, LOW);
//    delayMicroseconds(1000);
//  }
//  delay(1000);
//}
