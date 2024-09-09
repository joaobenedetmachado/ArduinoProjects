#include <Ultrasonic.h>
#include <Servo.h>
#include <SimpleTimer.h>

Servo MotoPecas;  // PINO 9
Servo Separador;  // PINO 10
Ultrasonic Sensor(12, 13);
const int ledMotorLigado = 7;
int distancia = 0;
bool estadoEsteira = 0;
const int BotaoEntradaPeca = 5;
const int BotaoEmergencia = 3;
int estados = 0;
int temp_ant = 0;
int pecasPequenas = 0;
int pecasGrandes = 0;
int Total = 0;

void setup() {
  Serial.begin(9600);
  MotoPecas.attach(9);
  Separador.attach(10);
  pinMode(ledMotorLigado, OUTPUT);
  pinMode(BotaoEntradaPeca, INPUT);
  pinMode(BotaoEmergencia, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BotaoEmergencia), stopAll, LOW);
}

void PecaNaEsteira() {
  MotoPecas.write(90);
  digitalWrite(ledMotorLigado, HIGH);
}

void DescansoEsteira() {
  MotoPecas.write(0);
  digitalWrite(ledMotorLigado, LOW);
}

void PecaPequena() {
  Separador.write(120);
  pecasPequenas++;
  Serial.println("TOTAL PECAS GRANDE :");
  Serial.print(pecasGrandes);
  Serial.println("TOTAL PECAS PEQUENAS :");
  Serial.print(pecasPequenas);
}

void SeparadorDescanso() {
  Separador.write(90);
}

void PecaGrande() {
  Separador.write(60);
  pecasGrandes++;
  Serial.println("TOTAL PECAS GRANDE :");
  Serial.print(pecasGrandes);
  Serial.println("TOTAL PECAS PEQUENAS :");
  Serial.print(pecasPequenas);
}

void loop() {
  bool bEntrada = digitalRead(BotaoEntradaPeca);
  Serial.println(estados);
  switch (estados) {
    case 0:
      if (bEntrada == 1) {
        estados = 1;
        Serial.println("BOTAOPRESSIONADO!");
      }
      break;
    case 1:
      distancia = Sensor.read();
      PecaNaEsteira();
      temp_ant = millis();
      estados = 2;
      break;
    case 2:
      if (millis() - temp_ant > 1000) {
        DescansoEsteira();
        estados = 3;
      }
      break;
    case 3:
      if ((distancia > 30) && (distancia < 45)) {
        PecaPequena();
      } else if ((distancia < 30) && (distancia > 15)) {
        PecaGrande();
      } else {
        SeparadorDescanso();
      }
      estados = 1;
      break;
    default:
      estados = 0;
      break;
  }
}

void stopAll() {
  DescansoEsteira();
  SeparadorDescanso();
  estados = 0;
  Serial.println("ERRO! PROCESSOS PARADOS!");
}