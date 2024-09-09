#include <Ultrasonic.h>
Ultrasonic ultrasonic(12, 13);
int distance;
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
void setup() {
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}
void loop() {
  distance = ultrasonic.read();
  Serial.print("Distance in CM: ");
  Serial.println(distance);
}
