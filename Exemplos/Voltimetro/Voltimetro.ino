#include <TimerOne.h>
#include <MultiFuncShield.h>

int analog0;
float tensao;

void setup() {
  Timer1.initialize();
  MFS.initialize(&Timer1);
}

void loop() {
  analog0=analogRead(A0);
  tensao=(analog0*5.0)/1023.0;
  MFS.write(tensao,3);
}
