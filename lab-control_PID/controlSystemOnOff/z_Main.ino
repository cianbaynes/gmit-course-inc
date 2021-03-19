#define PIN_LED1 3
#define pinSensor analogRead(A0)


Relay relayblink = Relay(PIN_LED1, 500, 500);
 lightSensor light(A0, 500);



void setup() {
 // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  relayblink.check();
  light.lightmeasurement();
 

Serial.print("light= "); Serial.println
(light.GetVoltage());
}
