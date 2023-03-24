#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int menu=0,cont=0;
char valor[5];

void trocatela(int tela)
{
   switch (tela)
   {
        case 0: lcd.setCursor(0,0);
                lcd.print("    Contagem    ");
                lcd.setCursor(0,1);
                sprintf(valor,"%03u",cont);
                lcd.print(valor);
                break;
        case 1: lcd.setCursor(0,0);
                lcd.print("Tela 2          ");
                break;
        case 2: lcd.setCursor(0,0);
                lcd.print("Tela 3          ");
                break;
   }
}

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
  if (verificabot() == 'b')
  {
     ++menu;
     if (menu==3)
       menu=0;
     delay(150);
  }
  if (verificabot() == 'c')
  {
    --menu;
    if (menu == -1)
      menu = 3;
     delay(150);
  }
  if (verificabot() == 'e')
  {
      ++cont;
      delay(150);
  }
    if (verificabot() == 'd')
  {
      --cont;
      delay(150);
  }
  trocartela(menu);


}
