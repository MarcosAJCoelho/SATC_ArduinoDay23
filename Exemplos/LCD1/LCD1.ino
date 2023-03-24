#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int menu = 0;

char verificabot()
{
  char lido;
  int botao;
  botao = analogRead (0);  //Leitura do valor da porta analógica A0
  if (botao < 100) {  //direita
    lido = 'd';
  }
  else if (botao < 200) {  //cima
    lido = 'c';
  }
  else if (botao < 400) { //baixo
    lido = 'b';
  }
  else if (botao < 600) { //esquerda
    lido = 'e';
  }
  else if (botao < 800) { //select
    lido = 's';
  }
  delay(300);

  return lido;

}

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Faculdade");
  lcd.setCursor(0, 1);
  lcd.print("SATC");
  delay(1000);
  lcd.clear();
  Serial.begin(9600);
}
void loop()
{
  if (verificabot() == 'd')
  {
    lcd.setCursor(0, 0);
    lcd.print("direita");
  }
  if (verificabot() == 'e')
  {
    lcd.setCursor(0, 0);
    lcd.print("esquerda");
  }
}
