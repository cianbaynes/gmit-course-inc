
class depthSensor{
private:
byte pinSensor;
float voltage = 0;
float value=0;
float distance=0;
float angle=0;
unsigned long readInterval = 0;
unsigned long nextChangeTime = 0;

public:
depthSensor(byte pinSense, unsigned long readInterv) {
      this->pinSensor = pinSense;
      this->readInterval = readInterv;
      pinMode(pinSensor, INPUT);
}
  void Distancemeasurement(){
     unsigned long currentTime = millis();
      if(currentTime >= nextChangeTime) {
        value = analogRead(pinSensor);
        voltage = value * (5.0/1023.0);
        distance =  -21.006*voltage+58.543;
        angle = (distance-10)*(180/10);
        nextChangeTime = currentTime + readInterval;
      }
  }
  
  
float getVoltage(){
  return voltage;
}
float getDistance(){
return distance;
  
}
int getAngle(){
  return angle;
}

 

  
};
