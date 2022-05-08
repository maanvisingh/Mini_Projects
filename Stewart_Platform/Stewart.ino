#include <Servo.h>

Servo myservo[7];

float DesireLen[6];
float ServoHornLen = 14.57;
float ConnectingRodLen = 38.65;
float HornConnectRodDistance =  3.85;
int ServoPos[6] = {90, 90, 90, 90, 90, 90};
float RaduisBottomPlate = 61.71; // bottom plate raduis with respect to rods
float BottomRodAngleDeg[6] = {353.6875, 6.3125, 113.6875, 126.3125, 233.6875, 246.3125}; // angle of rods convert to rad
float RadiusTopPlate = 59.51; // top plate raduis with respect to rods
float TopRodAngleDeg[6] = {330, 30, 90, 150, 210, 270};
float flatLength;
float  BottomRodAngleRad[6];
float TopRodAngleRad[6];
int DegY = 1;
int DegZ = 1;


float BottomPx[6] = {0, 0, 0, 0, 0, 0}; // bottom pts
float BottomPy[6] = {0, 0, 0, 0, 0, 0};
float BottomPz[6] = {0, 0, 0, 0, 0, 0};
float TopPx[6];
float TopPy[6];
float TopPz[6];
int moveX = 1;
int moveZ = 1;
float Z_Offset = 32.525;; // platform start Z
float pi = 3.14159265;

//change
float X_translation = 0; // desired Translation
float Y_translation = 0;
float Z_translation = 0;
//change
float X_rotationDeg = 0; // desired Angular Displacement
float Y_rotationDeg = 0;
float Z_rotationDeg = 0;


float X_rotationRad = X_rotationDeg / 57.2958; //to rad
float Y_rotationRad = Y_rotationDeg / 57.2958;
float Z_rotationRad = Z_rotationDeg / 57.2958;

void caluculate()
{
  for (int x = 0; x < 6; x++)
  {
    BottomRodAngleRad[x] = BottomRodAngleDeg[x] / 57.2958;
    TopRodAngleRad[x] = TopRodAngleDeg[x] / 57.2958;
    BottomPx[x] = RaduisBottomPlate * cos(BottomRodAngleRad[x]);
    BottomPy[x] = RaduisBottomPlate * sin(BottomRodAngleRad[x]);
    TopPx[x] = (RadiusTopPlate * cos(TopRodAngleRad[x]) * cos(X_rotationRad) * cos(Z_rotationRad)) + RadiusTopPlate * sin(TopRodAngleRad[x]) * (sin(X_rotationRad) * sin(Y_rotationRad) * cos(Z_rotationRad) - cos(X_rotationRad) * sin(Z_rotationRad)) + X_translation;
    TopPy[x] = (RadiusTopPlate * cos(TopRodAngleRad[x]) * cos(Y_rotationRad) * sin(Z_rotationRad)) + RadiusTopPlate * sin(TopRodAngleRad[x]) * (sin(X_rotationRad) * sin(Y_rotationRad) * sin(Z_rotationRad) + cos(X_rotationRad) * cos(Z_rotationRad)) + Y_translation;
    TopPz[x] = -RadiusTopPlate * cos(TopRodAngleRad[x]) * sin(Y_rotationRad) + (RadiusTopPlate * sin(TopRodAngleRad[x]) * sin(X_rotationRad) * cos(Z_rotationRad)) + Z_Offset + Z_translation;
    DesireLen[x] = sqrt((TopPx[x] - BottomPx[x]) * (TopPx[x] - BottomPx[x])  + (TopPy[x] - BottomPy[x]) * (TopPy[x] - BottomPy[x]) + (TopPz[x] - BottomPz[x]) * (TopPz[x] - BottomPz[x]));
    flatLength = sqrt((ConnectingRodLen * ConnectingRodLen) - (HornConnectRodDistance * HornConnectRodDistance));
    ServoPos[x] = (acos(((ServoHornLen * ServoHornLen) - (DesireLen[x] * DesireLen[x]) + (flatLength * flatLength)) / (DesireLen[x] * ServoHornLen * 2))) * (180 / pi);
    //    Serial.print(DesireLen[x]);
    //    Serial.print("  ");
    //    Serial.print(ServoPos[x]);
    //    Serial.println("  ");
    delay(4);
  }
  myservo[1].write(ServoPos[0] - 2);
  myservo[3].write(ServoPos[2] + 5);
  myservo[5].write(ServoPos[4]);
  myservo[2].write(180 - ServoPos[1] + 2);
  myservo[4].write(180 - ServoPos[3] + 2);
  myservo[6].write(180 - ServoPos[5] + 4);
}

void setup()
{
  for (int x = 1; x <= 6; x++) //set servos
  {
    myservo[x].attach(x + 2);
  }
  Serial.begin(9600);
}

void loop()
{
  for ( int w = 0; w < 3; w++)
  {
    for (int x = 0; x < 28; x++)
    {
      Z_translation = Z_translation + moveZ;
      caluculate();
      if (Z_translation == 7)
      {
        moveZ = -1;
      }
      if (Z_translation == -7)
      {
        moveZ = 1;
      }
    }
  }
  for ( int w = 0; w < 3; w++)
  {
    for (int x = 0; x < 24; x++)
    {
      X_translation = X_translation + moveX;
      caluculate();
      if (X_translation == 6)
      {
        moveX = -1;
      }
      if (X_translation == -6)
      {
        moveX = 1;
      }
    }
  }
  for (int w = 0; w < 3; w++)
  {
    for (int x = 0; x < 40; x++)
    {
      Y_rotationDeg = Y_rotationDeg + DegY;
      Y_rotationRad = Y_rotationDeg / 57.2958;
      caluculate();
      if (Y_rotationDeg == 10)
      {
        DegY = -1;
      }
      if (Y_rotationDeg == -10)
      {
        DegY = 1;
      }
    }
  }
  for (int w = 0; w < 3; w++)
  {
    for (int x = 0; x < 40; x++)
    {
      Z_rotationDeg = Z_rotationDeg + DegZ;
      Z_rotationRad = Z_rotationDeg / 57.2958;
      caluculate();
      if (Z_rotationDeg == 10)
      {
        DegZ = -1;
      }
      if (Z_rotationDeg == -10)
      {
        DegZ = 1;
      }
    }
  }




}
