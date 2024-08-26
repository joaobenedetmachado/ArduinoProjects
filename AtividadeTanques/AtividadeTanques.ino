#include <Ultrasonic.h> // integra as bibliotecas
#include "DHT.h"
#define DHTPIN 7 // configura de acordo com as classes
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

Ultrasonic ultrasonic(12, 13);
int nivelTanque;

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
  float temperatura = dht.readTemperature(); //le a temperatura e o nivel do tanque
  nivelTanque = ultrasonic.read();

  Serial.print(" Porcentagem do Tanque: "); //mostra porcentagem do tanque e a temperatura
  Serial.println(nivelTanque);
  Serial.print(F("%  Temperature: "));
  Serial.print(temperatura);

  if (nivelTanque > 30 && (temperatura >= 25 and temperatura <= 29)) { // se isso igual a TRUE, liga saida e desliga o resto
    digitalWrite(ledSaidaE, HIGH);
    digitalWrite(ledEntrada, LOW);
    digitalWrite(ledAlerta, LOW);
    digitalWrite(ledAquecimento, LOW);
  } else {
    if (nivelTanque < 30) { // caso nao, ele chega o tanque, 
      digitalWrite(ledSaidaE, LOW);
      digitalWrite(ledEntrada, HIGH);
      if (nivelTanque < 10) {
        digitalWrite(ledAlerta, HIGH);
        digitalWrite(ledEntrada, HIGH);
      } else {
        digitalWrite(ledAlerta, LOW);
        digitalWrite(ledEntrada, HIGH);
      }
    }
    if (temperatura < 25) { // a temperatura e tal para saber se precisa aquecer, abastecer e etc.
      if (nivelTanque > 10) {
        digitalWrite(ledAquecimento, HIGH);
        digitalWrite(ledEntrada, LOW);

      } else {
        digitalWrite(ledAquecimento, LOW);
        digitalWrite(ledEntrada, HIGH);
      }
    }
  }
}
