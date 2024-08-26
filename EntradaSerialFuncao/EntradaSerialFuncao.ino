int a;
int b;

void setup() {
  Serial.begin(9600);
}

int Multi(int a, int b) {
  int resultado = 0;
  for (int i = 0; i < b; i++) {
    resultado += a;
  }
  return resultado;
}

void print(int res) {
  Serial.print("O resultado é: ");
  Serial.println(res);
}

void loop() {
  Serial.print("Digite o primeiro valor: ");
  while (1) {
    if (Serial.available() > 0) {
      break;
    } 
  }
  a = Serial.parseInt();
  Serial.println(a);
  Serial.print("Digite o segundo valor: ");
  while (1) {
    if (Serial.available() > 0) {
      break;
    } 
  }
  b = Serial.parseInt();
  Serial.println(b);
  int res = Multi(a, b);
  print(res);
}
