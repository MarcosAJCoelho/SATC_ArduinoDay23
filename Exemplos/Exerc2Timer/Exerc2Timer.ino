#include <TimerOne.h>

#define liga A1
#define desl A2
#define led  13

int tempo=0;
boolean ativa=false;

void timer1()
{
  if (ativa)
  {
    ++tempo;
    Serial.print(tempo);
  }
}

void setup() {
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(timer1); 
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}

void loop() {
  if (digitalRead(liga)==LOW)
  {
      ativa=true;
      digitalWrite(led,LOW);
  }
  if ((ativa) && (tempo>2))
  {
     ativa=false;
     digitalWrite(led,HIGH);
  }
  if (digitalRead(desl)==LOW)
  {
    tempo=0;
  }

}
