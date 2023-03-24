#include <TimerOne.h>
#include <MultiFuncShield.h>

int analog0,porc;

void setup() {
  Timer1.initialize();
  MFS.initialize(&Timer1);
}

void loop() {
  analog0=analogRead(A0);
  porc=map(analog0,0,1023,0,100);
  MFS.write(porc);
  if (porc>=50)
  {
    MFS.beep(10,5,4,100,50);
  }
  else
  {
    MFS.beep(0);
  }
}
