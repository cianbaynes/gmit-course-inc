#define PIN_LED1 3
#define pinSensor A0
#define Servopin 9
#include <Servo.h>
Servo myservo;

/*
 *  BLINKER CLASS VARIABLES DECLARATION
 */
Blinker blink1 = Blinker(PIN_LED1, 500, 500);

depthSensor depthr(pinSensor, 500);

Servocian servoangle(Servopin, 500);

void setup() {
 // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  myservo.attach(Servopin);  // (pin)
}

void loop() {
  blink1.check();
  depthr.Distancemeasurement();
  servoangle.setdeptr(depthr.getDistance());

Serial.println(depthr.getVoltage());Serial.println(depthr.getDistance());
Serial.println("   ");

//myservo.write(servoangle.getAngle());  // tell servo to go to a particular angle
  //delay(1000);

  
}

  
