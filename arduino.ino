/*
Trabalho de IHM
Professor Marcelo Hashimoto
Senac-SP
Ezequiel França
Gabriel Vieira
 */

// botao que simula o ponto
int botao = 2;

// rotina de setup
void setup() {
  // inicializa a comunicação serial com 9600 bits por secondo:
  Serial.begin(9600);
  pinMode(botao, INPUT);
}


void loop() {
 
  int estado = digitalRead(botao);
  if(estado)
  Serial.println("SMS");
  delay(1);        // delay normalmente para estabilizar
}
