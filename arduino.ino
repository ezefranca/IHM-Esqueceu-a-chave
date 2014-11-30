
/*
Trabalho de IHM
Professor Marcelo Hashimoto
Senac-SP
Ezequiel França
Gabriel Vieira
*/
#include <LiquidCrystal.h>
// botao que simula o ponto
int botao = 10;
int apito = 7;
int bonus = 8;
#define tempo 10
int frequencia = 0;
LiquidCrystal lcd(12, 11, 7, 6, 3, 1);
char c;
int t;
int professor = 0;
// rotina de setup
void setup() {
// inicializa a comunicação serial com 9600 bits por secondo:
Serial.begin(9600);
pinMode(botao, INPUT);
pinMode(bonus, INPUT);
pinMode(apito, OUTPUT);
lcd.begin(16, 2); //Inicia o LCD com dimensões 16x2(Colunas x Linhas)
lcd.setCursor(0, 0); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
lcd.print("#--------------#"); //Escreve no LCD
lcd.setCursor(0, 1); //Posiciona o cursor na primeira coluna(0) e na segunda linha(1) do LCD
lcd.print("Sistema de Ponto");
}
//Rotina de Loop
void loop() {
int estado = digitalRead(botao);
if(estado){
  professor++;
  Serial.print("$");
  delay(1);
  Serial.print(professor);
  //Serial.print("S");
  tone(apito, 1000, 200);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("20:33 14/11/2014");
  lcd.setCursor(0, 1);
  lcd.print("Professor");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
  lcd.print("#--------------#"); //Escreve no LCD
  lcd.setCursor(0, 1); //Posiciona o cursor na primeira coluna(0) e na segunda linha(1) do LCD
  lcd.print("Sistema de Ponto");
  if(professor == 6)
      professor = 0;
}
int sirene = digitalRead(bonus);
if(sirene){
for (frequencia = 150; frequencia < 1800; frequencia += 1) {
tone(apito, frequencia, tempo);
delay(1);
}
for (frequencia = 1800; frequencia > 150; frequencia -= 1) {
tone(apito, frequencia, tempo);
delay(1);
}
}
delay(1); // delay normalmente utilizado para estabilizar a comunicao Serial
}
