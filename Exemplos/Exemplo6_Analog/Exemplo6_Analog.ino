int analog0 = 0;
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;

void setup()
{
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop()
{
  analog0 = analogRead(A0);
  if (analog0<340)
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
  if ((analog0>=340) && (analog0<680))
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);    
  }
  if ((analog0>=680) && (analog0<1000))
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);    
  }
  if (analog0>=1000))
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);    
  }  
}
