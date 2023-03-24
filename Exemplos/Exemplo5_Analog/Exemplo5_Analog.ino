int analog0=0;
char buffer[5];
void setup()
{
   Serial.begin(9600);
}

void loop()
{
    analog0=analogRead(A0);
    sprintf(buffer, "%04d",analog0 );
    Serial.println(buffer);
    delay(20);
}

