/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

// Motor control pins
const int in1 = 4;
const int in2 = 5;
const int in3 = 6;
const int in4 = 7;

// Motor enable pins
const int ena = 9;
const int enb = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);      //Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on arduino.

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Set the motor enable pins as outputs
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  // Serial.print("KeyPressed: ");
  // if (GamePad.isUpPressed())
  // {
  //   Serial.print("UP");
  //   digitalWrite(in1, LOW);
  //   digitalWrite(in2, HIGH);
  //   digitalWrite(in3, HIGH);
  //   digitalWrite(in4, LOW);
  //   analogWrite(ena, 255); // Set speed
  //   analogWrite(enb, 255); // Set speed
  // }

  // else if (GamePad.isDownPressed())
  // {
  //   Serial.print("DOWN");
  //   digitalWrite(in1, HIGH);
  //   digitalWrite(in2, LOW);
  //   digitalWrite(in3, LOW);
  //   digitalWrite(in4, HIGH);
  //   analogWrite(ena, 255); // Set speed
  //   analogWrite(enb, 255); // Set speed
  // }

  // else if (GamePad.isLeftPressed())
  // {
  //   Serial.print("Left");
  //   digitalWrite(in1, LOW);
  //   digitalWrite(in2, HIGH);
  //   digitalWrite(in3, LOW);
  //   digitalWrite(in4, HIGH);
  //   analogWrite(ena, 255); // Set speed
  //   analogWrite(enb, 255); // Set speed
  // }

  // else if (GamePad.isRightPressed())
  // {
  //   Serial.print("Right");
  //   digitalWrite(in1, HIGH);
  //   digitalWrite(in2, LOW);
  //   digitalWrite(in3, HIGH);
  //   digitalWrite(in4, LOW);
  //   analogWrite(ena, 255); // Set speed
  //   analogWrite(enb, 255); // Set speed
  // }

  // else if (GamePad.isSquarePressed())
  // {
  //   Serial.print("Square");
  //   digitalWrite(in1, LOW);
  //   digitalWrite(in2, HIGH);
  //   digitalWrite(in3, LOW);
  //   digitalWrite(in4, HIGH);
  //   analogWrite(ena, 255); // Set speed
  //   analogWrite(enb, 255); // Set speed
  // }

  // else if (GamePad.isCirclePressed())
  // {
  //   Serial.print("Circle");
  //   digitalWrite(in1, HIGH);
  //   digitalWrite(in2, LOW);
  //   digitalWrite(in3, LOW);
  //   digitalWrite(in4, HIGH);
  //   analogWrite(ena, 100); // Set speed
  //   analogWrite(enb, 100); // Set speed
  // }

  // else if (GamePad.isCrossPressed())
  // {
  //   Serial.print("Cross");
  // }

  // else if (GamePad.isTrianglePressed())
  // {
  //   Serial.print("Triangle");
  // }

  // else if (GamePad.isStartPressed())
  // {
  //   Serial.print("Start");
  // }

  // else if (GamePad.isSelectPressed())
  // {
  //   Serial.print("Select");
  // }
  // else {
  //   stopMotors();
  // }
  // Serial.print('\t');

  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println('\t');
  float meow = map(d,-7, 7, -255, 255);
  if (abs(meow) < 100){
    meow = 100;
  }
  else if (abs(meow) < 50){
    meow = 0;
  }
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(ena, meow); // Set speed
    Serial.println(meow);
    analogWrite(enb, meow); // Set speed
}

// Stop all motors
void stopMotors(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(ena, 0); // Set speed to 0
  analogWrite(enb, 0); // Set speed to 0
}
