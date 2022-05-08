int pwm[4] = {7, 6, 5, 4};
int dir[4] = {11, 10, 9, 8};
boolean val[4] = {false, false, true, false};
int i;
int analogPin = A7;
int junctionPulse = 3;
int readVal = 0;
int positionVal;
int junctionCount = 0;
int pp = 55; //50
int pp2 = 45;  //40

int pwmPin = 2;
int dirPin = 12;
int k = 80; //80
int j = 110; // 100

int irPin = 13;

void setup()
{
  for (i = 0; i < 4; i++)
  {
    pinMode(pwm[i], OUTPUT);
    pinMode(dir[i], INPUT);
  }
  pinMode(junctionPulse, INPUT);
  pinMode(analogPin, INPUT);
  pinMode(pwmPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  analogWrite(pwmPin, 0);
  delay(500);

  pinMode(irPin, INPUT);
  Serial.begin(9600);

}

void forward()
{
  digitalWrite(dir[0], val[0]);
  analogWrite(pwm[0], pp);
  digitalWrite(dir[1], !val[1]);
  analogWrite(pwm[1], pp);
  digitalWrite(dir[2], !val[2]);
  analogWrite(pwm[2], pp);
  digitalWrite(dir[3], val[3]);
  analogWrite(pwm[3], pp + 15);
}

void backward()
{
  digitalWrite(dir[0], !val[0]);
  analogWrite(pwm[0], pp);
  digitalWrite(dir[1], val[1]);
  analogWrite(pwm[1], pp);
  digitalWrite(dir[2], val[2]);
  analogWrite(pwm[2], pp);
  digitalWrite(dir[3], !val[3]);
  analogWrite(pwm[3], pp);
}

void clockwise()
{
  readVal = analogRead(analogPin);
  positionVal = ((float)readVal / 921) * 70;

  digitalWrite(dir[0], !val[0]);
  analogWrite(pwm[0], pp);
  digitalWrite(dir[1], !val[1]);
  analogWrite(pwm[1], pp);
  digitalWrite(dir[2], val[2]);
  analogWrite(pwm[2], pp);
  digitalWrite(dir[3], val[3]);
  analogWrite(pwm[3], pp);
}

void left()
{
  digitalWrite(dir[0], val[0]);
  analogWrite(pwm[0], pp2);
  digitalWrite(dir[1], val[1]);
  analogWrite(pwm[1], pp2);
  digitalWrite(dir[2], val[2]);
  analogWrite(pwm[2],  0); //pp2
  digitalWrite(dir[3], val[3]);
  analogWrite(pwm[3], 0); //pp2
}

void right()
{
  digitalWrite(dir[0], !val[0]);
  analogWrite(pwm[0], pp2);
  digitalWrite(dir[1], !val[1]);
  analogWrite(pwm[1], pp2);
  digitalWrite(dir[2], !val[2]);
  analogWrite(pwm[2], 0); //pp2
  digitalWrite(dir[3], !val[3]);
  analogWrite(pwm[3], 0); //pp2
}

void Stop()
{

  analogWrite(pwm[0], 0);

  analogWrite(pwm[1], 0);

  analogWrite(pwm[2], 0);

  analogWrite(pwm[3], 0);
}

void gripperup()
{
  digitalWrite(dirPin, LOW);
  analogWrite(pwmPin, j);
  delay(700); //600

  analogWrite(pwmPin, 0);
  delay(2000);
  j = j - 5;

}


void gripperdown()
{
  digitalWrite(dirPin, HIGH);
  analogWrite(pwmPin, k);
  delay(300);

  analogWrite(pwmPin, 0);
  delay(2000);

  k = k + 20;
}

void lsa()
{
  readVal = analogRead(analogPin);
  positionVal = ((float)readVal / 921) * 70;

  //Serial.println(positionVal);

  if (positionVal <= 25)
    left();

  else if (positionVal <= 52)
    forward();

  else if (positionVal <= 70)
    right();

  else
    Stop();
}

void lsaback()
{
  readVal = analogRead(analogPin);
  positionVal = ((float)readVal / 921) * 70;

  // Serial.println(positionVal);

  if (positionVal <= 25)
    left();

  else if (positionVal <= 52)
    backward();

  else if (positionVal <= 70)
    right();

  else
    Stop();
}

void loop()
{
  lsa();
  if (digitalRead(junctionPulse))
  {
    Stop();
    while ((junctionCount % 2 == 0) && digitalRead(irPin) != 0)
    {
      lsa();
    }

    Stop();

    if (junctionCount % 2 == 0)
      gripperup();
    else
      gripperdown();

    Stop();
    delay(500);

    //    lsaback();
    //    delay(5000);

    backward();
    delay(1500);

    //    lsaback();
    //    delay(3000);

    Stop();
    delay(500);

    clockwise();
    delay(5000);

    while (!(positionVal < 50 && positionVal > 35))
    {
      clockwise();
    }


    digitalWrite(dir[2], val[2]);
    analogWrite(pwm[2], pp);
    digitalWrite(dir[3], !val[3]);
    analogWrite(pwm[3], pp);
    delay(1000);

    Stop();
    delay(10);

    junctionCount++;
  }

  //Serial.println(digitalRead(irPin));

}
