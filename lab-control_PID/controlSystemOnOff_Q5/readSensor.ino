
class lightSensor{
private:
float pinSensor;
float voltage = 0;
int val = 0;
unsigned long readInterval = 0;
unsigned long nextChangeTime = 0;

public:
lightSensor(float pinSensor, unsigned long readInterval) {
      this->pinSensor = pinSensor;
      this->readInterval = readInterval;
      pinMode(analogRead(pinSensor), INPUT);
}
  void lightmeasurement(){
     unsigned long currentTime = millis();
      if(currentTime >= nextChangeTime) {
         val=analogRead(pinSensor);
      
      voltage = val * (5.0/1023.0);
         nextChangeTime = currentTime + readInterval;

         
      }
  }

  float GetVoltage(){
  return voltage;

  }



  
};
