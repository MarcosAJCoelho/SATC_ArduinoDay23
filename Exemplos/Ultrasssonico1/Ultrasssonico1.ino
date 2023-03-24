#include "Ultrasonic.h"
Ultrasonic ultrasonic(5,6);

int medida,tipo;
void setup() {
  Serial.begin(9600);
}
void loop()
{
  if (!digitalRead(A1))
  {
    ++tipo;
    if (tipo==2)
      tipo=0;
  }
  if (tipo==0)
    medida=(ultrasonic.Ranging(CM))/100;
  else 
    medida=ultrasonic.Ranging(INC);
  Serial.print("Distância: ");
  Serial.println(medida);
    
  delay(1000);
}




