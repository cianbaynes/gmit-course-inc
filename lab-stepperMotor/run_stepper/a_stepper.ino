//Control pins
#define PinA 2
#define PinB 3
#define PinC 4      
#define PinD 5
#define NUMBER_OF_STEPS_PER_REV 512

//Example function to write logic to pins

void writePINS(int a,int b,int c,int d){
  digitalWrite(PinA,a);
  digitalWrite(PinB,b);
  digitalWrite(PinC,c);
  digitalWrite(PinD,d);
  }
  
  //Example
  void oneStepCW(int delayvalue){
    writePINS(1,0,0,0);
    delay(delayvalue);
    writePINS(1,1,0,0);
    delay(delayvalue);
    writePINS(0,1,0,0);
    delay(delayvalue);
    writePINS(0,1,1,0);
    delay(delayvalue);
    writePINS(0,0,1,0);
    delay(delayvalue);
    writePINS(0,0,1,0);
    delay(delayvalue);
    writePINS(0,0,0,1);
    delay(delayvalue);
    writePINS(1,0,0,1);
    delay(delayvalue);
  }
    
  void oneStepCCW (int delayvalue){
    writePINS(1,0,0,1);
    delay(delayvalue);
    writePINS(0,0,0,1);
    delay(delayvalue);
    writePINS(0,0,1,1);
    delay(delayvalue);
    writePINS(0,0,1,0);
    delay(delayvalue);
    writePINS(0,1,1,0);
    delay(delayvalue);
    writePINS(0,1,0,0);
    delay(delayvalue);
    writePINS(1,1,0,0);
    delay(delayvalue);
    writePINS(1,0,0,0);
    delay(delayvalue);
  }
