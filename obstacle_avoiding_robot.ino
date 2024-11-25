#include <AFMotor.h>
#define INPUT_PIN A0

long duration = 0;
int distance = 0;
int maxSpeed = 150;
int turningDelay = 300;

AF_DCMotor motorLeft(4, MOTOR12_1KHZ), motorRight(3,  MOTOR12_1KHZ);

void setup() {

  pinMode(INPUT_PIN, INPUT);
  Serial.begin(9600);
  readSensor();
  delay(50);
  readSensor();
  delay(50);
  readSensor();
  delay(50);

}

void loop() {
  delay(40);
  if (readSensor()) {
    stopRuning();
    delay(turningDelay);
    turnLeft();
    delay(turningDelay);
    stopRuning();
  }else
  {
      runForward();
  }

  readSensor();
}

bool readSensor() {
  int sensorStatus = digitalRead(INPUT_PIN);
  if(sensorStatus){
    return false;
  } else {
    return true;
  }
}
void runForward() {
  motorLeft.setSpeed(maxSpeed);
  motorLeft.run(FORWARD);
  motorRight.setSpeed(maxSpeed);
  motorRight.run(FORWARD);
}
void turnLeft() {
  delay(turningDelay);
  motorLeft.setSpeed(maxSpeed);
  motorLeft.run(BACKWARD);
  motorRight.setSpeed(maxSpeed);
  motorRight.run(FORWARD);
}
void stopRuning() {
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}