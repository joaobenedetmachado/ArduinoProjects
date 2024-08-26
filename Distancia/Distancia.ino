#include <Ultrasonic.h>
Ultrasonic ultrasonic(12, 13);
int distance;
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}
void loop() {
  distance = ultrasonic.read();
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  if (distance <= 20) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } else if (distance > 20 && distance <= 100) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  } else if (distance > 100) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
}
