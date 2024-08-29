#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver board1 = Adafruit_PWMServoDriver();  // Initialize the PWM servo driver

#define SERVOMIN  125  // Minimum pulse length count (out of 4096) 0 degrees
#define SERVOMAX  625  // Maximum pulse length count (out of 4096) 270 degrees

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  Wire.begin();  // Initialize I2C communication
  board1.begin();  // Initialize the PWM servo driver
  board1.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  for (int i = 0; i < 5; i++) {
    board1.setPWM(i, 0, angleToPulse(0));
  }


  for (int angle = 0; angle < 181; angle += 10) {
    for (int i = 0; i < 5; i++) {
      board1.setPWM(i, 0, angleToPulse(angle));
    }
  }
}

void loop() {
 

}

int angleToPulse(int ang) {
  int pulse = map(ang, 0, 180, SERVOMIN, SERVOMAX);
  Serial.print("Angle: ");
  Serial.print(ang);
  Serial.print(" pulse: ");
  Serial.println(pulse);
  return pulse;
}
