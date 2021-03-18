#define PIN_LED1 3
#define pinSensor A1
//#define Servopin 9
#include <Servo.h>
Servo myservo;

/*
 *  BLINKER CLASS VARIABLES DECLARATION
 */
Blinker blink1 = Blinker(PIN_LED1, 500, 500);

depthSensor depthread(pinSensor, 500);


void setup() {
 // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  myservo.attach(9,600,2300);  // (pin, min, max)
}

void loop() {
  blink1.check();
  depthread.Distancemeasurement();
  

Serial.println(depthread.getVoltage());Serial.println(depthread.getDistance());
Serial.println("   ");

myservo.write(depthread.getAngle());  // tell servo to go to a particular angle
  //delay(1000);

  
}

  
