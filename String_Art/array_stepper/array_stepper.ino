#define dirPin 2
#define stepPin 3
#define arr_size 100

int stepsPerRevolution;
int dir;
String input;
String steps;
int exactStep;

void setup()
{
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  dir = HIGH;
  int stepsPerRevolution[arr_size] = {};

  digitalWrite(dirPin, dir);
  int currentPos = 0;
  int oldPos = 0;

  for (int i = 0; i < stepsPerRevolution[0]; i++)
  {
    Serial.println(stepsPerRevolution[j]);
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }

  for (int j = 1; i < arr_size; i++)
  {
    currentPos = stepsPerRevolution[j];
    oldPos = stepsPerRevolution[j - 1];
    exactStep = 
    
    for (int i = 0; i < ; i++)
    {
      Serial.println(stepsPerRevolution[j]);
      // These four lines result in 1 step:
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(1000);
    }
    delay(1000);
  }
}
