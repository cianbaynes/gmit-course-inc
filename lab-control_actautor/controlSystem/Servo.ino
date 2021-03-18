#include <Servo.h>
//#include <c_depthSensor>
Servo myservo;

//depthSensor depthread(pinSensor, 500);


//the servo is for between 4-6Vdc which suits the Aduino voltage of 5Vdc
// the servo has three wires redo, black and white. The red to be connected to the 5V on the arduino, the black to the ground and white to Pin 9 which i have defined.
//the current draw of the servo is 140mA +/-50mA.
//Pulse-width modulation, 0.75–2.25 ms high pulse, 20 ms intervals
class Servocian{
  private:
byte ServoPin;
unsigned long delayon;
unsigned long nextTime;
int servoangle;
float tempdepthr;
  public:
  Servocian(byte ServoPinc, unsigned long delayone){
    this->ServoPin = ServoPinc;
    this->delayon = delayone;
    pinMode(ServoPin, OUTPUT);
  }

  void setdepthr(int depthr){
    tempdepthr=depthr;
  }
  void setrun(){
  unsigned long presentTime = millis();
      if(presentTime >= nextTime) {
        servoangle=map(tempdepthr, 10, 20, 0, 180); // the servo motor holds any position between 0 and 180 degrees therefor we are mapping from 0 - 180 degrees
        nextTime = presentTime + delayon;
      }
    
  }
  float Getangle(int servoangle){
    return servoangle;
  }
  
};
