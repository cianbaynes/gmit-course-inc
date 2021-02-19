#define PIN_LED1 3
#define pinSensor A0


/*
 *  BLINKER CLASS VARIABLES DECLARATION
 */
Blinker blink1 = Blinker(PIN_LED1, 500, 500);

depthSensor depthread = depthSensor(pinSensor, 500);


void setup() {
 // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  blink1.check();
  depthread.Distancemeasurement();

 
}
