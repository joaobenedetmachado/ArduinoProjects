int porta = A1;
int valor;
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;

void setup() {
  Serial.begin(9600);
  pinMode(porta, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  valor = analogRead(porta);
  Serial.println(valor);
  delay(1);

  if (valor > 200) {
    digitalWrite(led1, LOW);
  } else {
    digitalWrite(led1, HIGH);
  }
  if (valor < 300) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }
  if (valor < 400) {
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
  }
}
