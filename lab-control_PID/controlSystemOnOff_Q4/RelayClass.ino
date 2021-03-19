class Relay {
  private:
    byte pinLED;

    boolean ledState = LOW;

    unsigned long timeLedOn;
    unsigned long timeLedOff;

    unsigned long nextChangeTime = 0;
    float temporaryvolt;

  public:
    Relay(byte pinLED, unsigned long timeLedOn, unsigned long timeLedOff) {
      this->pinLED = pinLED;
      this->timeLedOn = timeLedOn;
      this->timeLedOff = timeLedOff;

      pinMode(pinLED, OUTPUT);
    }

    void setvoltage(float voltage){
     temporaryvolt=voltage;
    }

    // Checks whether it is time to turn on or off the LED.
    void check() {
      unsigned long currentTime = millis();

      if(currentTime >= nextChangeTime) {

        if(temporaryvolt<=3) {
          // LED is currently turned On. Turn Off LED.
          ledState = LOW;
          nextChangeTime = currentTime + timeLedOff;
        }
        else{
          // LED is currently turned Off. Turn On LED.
          ledState = HIGH;
          nextChangeTime = currentTime + timeLedOn;
        }

        digitalWrite(pinLED, ledState);
      }
    }
};
