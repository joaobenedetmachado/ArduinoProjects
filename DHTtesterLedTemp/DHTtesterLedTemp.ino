#include "DHT.h"
#define DHTPIN 3
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

const int led1 = 7;
const int led2 = 6;
const int led3 = 5;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
}

void loop() {
  delay(100);
  float t = dht.readTemperature();
  if (t <= 25) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } else if (t > 25 && t <= 30) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  } else if (t > 30) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
}
