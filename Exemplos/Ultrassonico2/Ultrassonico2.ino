#include <TimerOne.h>
#include <MultiFuncShield.h>
#include "Ultrasonic.h"
Ultrasonic ultrasonic(5,6);

int medida;

void setup() {
  Timer1.initialize();
  MFS.initialize(&Timer1);
}

void loop() {
   medida=(ultrasonic.Ranging(CM));
   MFS.write(medida);
   if (medida>=0 && medida<10)
   {
     digitalWrite(10,LOW);
     digitalWrite(11,HIGH);
     digitalWrite(12,HIGH);
     digitalWrite(13,HIGH);
   }
   if (medida>=11 && medida<25)
   {
     digitalWrite(10,LOW);
     digitalWrite(11,LOW);
     digitalWrite(12,HIGH);
     digitalWrite(13,HIGH);
   }
   if (medida>=26 && medida<40)
   {
     digitalWrite(10,LOW);
     digitalWrite(11,LOW);
     digitalWrite(12,LOW);
     digitalWrite(13,HIGH);
   }
   if (medida>=41)
   {
     digitalWrite(10,LOW);
     digitalWrite(11,LOW);
     digitalWrite(12,LOW);
     digitalWrite(13,LOW);
   }




   
}
