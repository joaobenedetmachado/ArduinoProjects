int porta = A1;
int valor;

void setup() {
  Serial.begin(9600);
  pinMode(porta, INPUT);
}

void loop() {
  valor = analogRead(porta);
  Serial.println(valor);
}
