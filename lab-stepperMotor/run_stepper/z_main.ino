//This has not been done in a class. This should have been completed in a class. I know how to do it from previous labs but i ran out of time
//to create the class

#define PinE 7
int buttonState=0;
void setup() {
  // put your setup code here, to run once:
pinMode(PinA, OUTPUT);
pinMode(PinB, OUTPUT);
pinMode(PinC, OUTPUT);
pinMode(PinD, OUTPUT);
pinMode(PinE, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

//for(int i=0; i<512; i++){
// oneStepCW(10); 
//}
//for(int i=0; i<512; i++){
// oneStepCCW(50);
//}

int delayvalue= analogRead (A0);
delayvalue=map(delayvalue, 5, 1023, 0, 200);
analogWrite(9, delayvalue);

buttonState =digitalRead(PinE);
if (buttonState==HIGH){
oneStepCW(delayvalue);
}else{
oneStepCCW(delayvalue);
}
 
}
