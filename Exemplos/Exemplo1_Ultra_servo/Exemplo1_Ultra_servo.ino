#include <Servo.h>

#include <LiquidCrystal.h>

Servo myservo;  // create servo object to control a servo

int Trig = 9;
int Echo = 8;
int DistCM = 0;
int pos = 0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
char dado[16];

void setup()
{
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  lcd.print("Teste");
  myservo.attach(6);
  }

long readUltrassom(){
  digitalWrite(Trig,LOW);
  delayMicroseconds(2);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);
  return pulseIn(Echo,HIGH);
}

void loop()
{
  DistCM=readUltrassom()/58;
    Serial.println(DistCM);
    lcd.setCursor(0,0);
    lcd.print("Dist = ");
    lcd.print(DistCM);  
    delay(50);
    myservo.write(50);

}
