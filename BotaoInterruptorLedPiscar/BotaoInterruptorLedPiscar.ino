#include <SimpleTimer.h>
volatile byte state = LOW;
const int led1 = 13;
const byte interruptPin = 2;

// Create a first timer and specify its interval in milliseconds
SimpleTimer firstTimer(1000);

void setup()
{
    Serial.begin(9600);
    pinMode(led1, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), blink, LOW);
}

void loop()
{
  digitalWrite(led1, state);
    if (firstTimer.isReady()) {            // Check is ready a first timer
        Serial.println("1 seconds have passed");
        state = !state;
        firstTimer.reset();
    }
}

void blink() {
  state = LOW;
}