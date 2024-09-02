const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, LOW);
  // FALLING : Aciona a interrupção quando o botão é pressionado (nível baixo)
  // RISING : Aciona a interrupção quando o botão é liberado (nível alto)
  // LOW : Aciona a interrupção enquanto o botão estiver pressionado (nível baixo)
  // CHANGE : Aciona a interrupção em qualquer mudança de nível (subida ou descida)
}

void loop() {
  digitalWrite(ledPin, state);
}

void blink() {
  state = !state;
}
