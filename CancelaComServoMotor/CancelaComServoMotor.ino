#include <Ultrasonic.h> 
#include <Servo.h>

Ultrasonic ultrasonic(11, 12);

Servo myservo;  
const int buzzer = 5;
int pos = 0;
const int pinBotao = 7;
int h;
bool carroPresente = false;
unsigned long tempoAbertura;
const unsigned long intervaloFechamento = 2000;
bool cancelaAberta = false;

void setup() {
  myservo.attach(9);
  pinMode(pinBotao, INPUT);
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void AbrirCancela() {
  myservo.write(90);
}

void FecharCancela() {
  myservo.write(0);
}


void loop() {
  unsigned long currentMillis = millis();
  bool b1 = digitalRead(pinBotao);
  h = ultrasonic.read();

  if (h < 10) {
    carroPresente = true;
    Serial.println("Carro presente! Aperte o botão!");
    if (b1 == HIGH && !cancelaAberta) {
      AbrirCancela();
      tempoAbertura = currentMillis;  
      cancelaAberta = true;
    }
  } else {
    Serial.println("Carro não presente!");
    carroPresente = false;
  }

  if (cancelaAberta && (currentMillis - tempoAbertura >= intervaloFechamento)) {
    FecharCancela();
    cancelaAberta = false;
  }
}
