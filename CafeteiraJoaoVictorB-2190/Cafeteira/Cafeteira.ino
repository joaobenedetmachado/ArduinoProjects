#include <Ultrasonic.h>  //importando e configurando as bibliotecas
Ultrasonic ultrasonic(12, 13);
#include "DHT.h"
#define DHTPIN 3
#define DHTTYPE DHT11
#include <SimpleTimer.h>
DHT dht(DHTPIN, DHTTYPE);


int distancia;  //declaracao de variaveis e constantes
const int ledAguaEsquentando = 8;
const int ledTirarCopo = 7;
const int Botao = 4;
int estado = 0;
int temp_ant = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledAguaEsquentando, OUTPUT);
  pinMode(ledTirarCopo, OUTPUT);
  pinMode(Botao, INPUT_PULLUP);
  Serial.println(F("DHTxx test!"));
  dht.begin();
}

void loop() {
  float temperatura = dht.readTemperature();
  distancia = ultrasonic.read();
  Serial.print("Distance in CM: ");
  Serial.println(distancia);
  Serial.println(estado);
  Serial.println(temperatura);
  bool botaoLigar = digitalRead(Botao);

  switch (estado) {
    case 0:
      digitalWrite(ledAguaEsquentando, LOW);
      digitalWrite(ledTirarCopo, LOW);
      if (botaoLigar == LOW) {
        estado = 1;
      }
      break;
    case 1:
      if (temperatura < 26) {
        //ESQUENTADO
        digitalWrite(ledAguaEsquentando, HIGH);
      } else {
        digitalWrite(ledAguaEsquentando, LOW);
        estado = 2;
        //ESQUENTOU E VAI COMECAR A FAZER O CAFE
      }
      break;
    case 2:
      if (distancia < 6) {
        Serial.println("TEM COPO");
        temp_ant = millis();
        if (millis() - temp_ant > 10000) {
          //espera o tempo passar
          estado = 3;
        }
      } else {
        Serial.println("COLOCAR COPO");
      }
      break;
    case 3:
      if (distancia < 6) {
        // se ainda tiver o copo, é para retirar o cafe, entao o led acende;
        digitalWrite(ledTirarCopo, HIGH);
        Serial.println("TEM COPO");
      } else {
        Serial.println("NAO TEM COPO");
        // se nao tive mais o copo, entao estado volta para 0, assim reiniciando a maquina de estados finitos;
        estado = 0;
      }
      break;
    default:
      estado = 0;
      break;
  }
}
