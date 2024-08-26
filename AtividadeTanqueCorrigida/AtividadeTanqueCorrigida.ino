#include <Ultrasonic.h> // integra as bibliotecas
#include "DHT.h"

#define DHTPIN 7 // configura de acordo com as classes
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

Ultrasonic ultrasonic(11, 12);
int h;

const int ledEntrada = 2; //define os pinos do led's
const int ledSaidaE = 3;
const int ledAquecimento = 4;
const int ledAlerta = 5;


void setup() {
  pinMode(ledEntrada, OUTPUT); // configura I e O's
  pinMode(ledSaidaE, OUTPUT);
  pinMode(ledAquecimento, OUTPUT);
  pinMode(ledAlerta, OUTPUT);
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  float t = dht.readTemperature(); //le a temperatura e o nivel do tanque
  h = ultrasonic.read();

    Serial.print(" Porcentagem do Tanque: "); //mostra porcentagem do tanque e a temperatura
    Serial.println(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);

  if (h == 0) {
    digitalWrite(ledEntrada, HIGH);
  } else {
    digitalWrite(ledEntrada, LOW);
  } 

  if ((h < 20) && (t > 24) && (t < 29)) {
    digitalWrite(ledSaidaE, HIGH);
  } else {
    digitalWrite(ledSaidaE, LOW);
  }

  if ((t<24) && (h < 320)) {
    digitalWrite(ledAquecimento, HIGH);
  } else {
    digitalWrite(ledAquecimento, LOW);
  }

  if (h > 360) {
    digitalWrite(ledAlerta, HIGH);
  } else {

    digitalWrite(ledAlerta, LOW);
  }
   
}
