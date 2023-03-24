#include <TimerOne.h>

#define led  13
#define led1 12
#define s1   A1

int tempoled = 0;

void timer1(void)
{
  ++tempoled; 
  Serial.println(tempoled);
}

void setup() {
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(s1,INPUT);
  
  Timer1.initialize(500000); //tempo de interrupção do timer
  Timer1.attachInterrupt(timer1);//liga interrupção do timer
  Serial.begin(9600);
}

void loop() {
    if (tempoled==2)
    {
      digitalWrite(led,HIGH);
    }
    if (tempoled==4)
    {
      digitalWrite(led,LOW);
      tempoled=0;
    }

    if (digitalRead(s1)==1)
      digitalWrite(led1,HIGH);
    else
      digitalWrite(led1,LOW);
 

}








