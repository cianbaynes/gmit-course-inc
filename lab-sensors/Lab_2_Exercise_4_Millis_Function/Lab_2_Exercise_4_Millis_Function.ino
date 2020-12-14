// Connect between 5V and GND, connect the digital output into A0, open the serial plotter and serial monitor in the tools tab.
// Modifying the POT will then change the output voltage reading between 0 and 1203
// Connecting the depth sensor and opening the serial plotter shows the graph moving as an object is moved closer and further from the depth plotter

// Define the number of samples to keep track of. The higher the number, the
// more the readings will be smoothed, but the slower the output will respond to
// the input. Using a constant rather than a normal variable lets us use this
// value to determine the size of the readings array.
const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A0;
long timeNow=0;
long timer=0;
void setup() {
  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(inputPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
 

 
  
    timeNow=millis();
    if((timeNow-timer)>=1000){ //outputting the result every 1 second when set to 1000
       Serial.println(average); 
      timer=timeNow;
      
    }
  }
  
 
