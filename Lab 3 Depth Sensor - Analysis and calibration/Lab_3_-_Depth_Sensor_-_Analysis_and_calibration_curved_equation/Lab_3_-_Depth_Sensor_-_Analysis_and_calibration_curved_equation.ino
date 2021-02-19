void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0/1023.0);
  // Calibration formula
  float distance = (10.878*(pow(voltage, 4)))-(88.826*(pow(voltage, 3)))+(261.19*(pow(voltage, 2)))- (335.38*voltage)+176.66; //this is the equation to the line that was generated suing the excel sheet.

  
  Serial.print("Distance= "); Serial.print(distance); Serial.print("cm   . Voltage= "); Serial.print(voltage); Serial.print("  ");//This will plot the voltage and the distances
  Serial.println("  ");

}
