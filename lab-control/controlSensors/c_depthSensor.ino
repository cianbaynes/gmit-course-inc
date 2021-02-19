
class depthSensor{
private:
byte pinSensor;
float voltage = 0;
float distance = 0;
unsigned long readInterval = 0;
unsigned long nextChangeTime = 0;

public:
depthSensor(byte pinSensor, unsigned long readInterval) {
      this->pinSensor = pinSensor;
      this->readInterval = readInterval;
      pinMode(pinSensor, INPUT);
}
  void Distancemeasurement(){
     unsigned long currentTime = millis();
      if(currentTime >= nextChangeTime) {
         nextChangeTime = currentTime + readInterval;
      }
  
float voltage = pinSensor * (5.0/1023.0);
  
float distance =  -21.006*voltage+58.543;
 Serial.print("Distance= "); Serial.print(distance); Serial.print("cm   . Voltage= "); Serial.print(voltage); Serial.print("  ");
  
}

  
};


/*
void setup1() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

}

void loop1() {
  // read the input on analog pin 0:
  
 
  // Calibration formula
  
 // float distance1 = (10.878*(pow(voltage, 4)))-(88.826*(pow(voltage, 3)))+(261.19*(pow(voltage, 2)))- (335.38*voltage)+176.66; //this is the equation to the line that was generated suing the excel sheet.

  Serial.print("Distance= "); Serial.print(distance); Serial.print("cm   . Voltage= "); Serial.print(voltage); Serial.print("  ");
  //Serial.print("Distance1= "); Serial.print(distance); Serial.print("cm   . Voltage= "); Serial.print(voltage); Serial.print("  ");//This will plot the voltage and the distances
  Serial.println("  ");

};*/
