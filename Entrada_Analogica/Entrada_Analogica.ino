const int pin_entrada = A0;
const int pinLed = 9;
int valor;
float tensao;

void setup() {
  Serial.begin(9600);
  pinMode(pin_entrada, INPUT);
}


void loop() {
  valor = analogRead(pin_entrada);
  tensao = float(valor) * 255 / 1023;
  Serial.print("Tensao = ");
  Serial.print(tensao);
  Serial.println(" V");

  analogWrite(pinLed, tensao);

}
