void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0/1023.0);
  // Calibration formula
  float distance = -21.006*voltage+58.543;

  
  Serial.print("Distance= "); Serial.print(distance); Serial.print("cm   . Voltage= "); Serial.print(voltage); Serial.print("  ");
  Serial.println("  ");

}
