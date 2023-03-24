const int pulso = 2;
const int reset = 3;

const int vd = 8;
const int am = 9;
const int vm = 10;


boolean auxpulso=false;
int contador=0;

void setup() {
  pinMode(pulso,INPUT);
  pinMode(reset,INPUT);
  pinMode(vd,OUTPUT);
  pinMode(am,OUTPUT);
  pinMode(vm,OUTPUT);        
  Serial.begin(9600);
}

void loop() {
  if ((digitalRead(pulso)==HIGH) && (auxpulso==false))
  {
    ++contador; //contador=contador+1;  //incrementa a variável contador
    Serial.print("Contador = ");        //imprime texto Contador =
    Serial.println(contador);           //imprime valor da variavel contador
    auxpulso=true;                      //faz estado de subida verdadeiro
    delay(400);                         //aguarda 400ms
  }
  else if (digitalRead(pulso)==LOW)     //se entrada desligar
  {
    auxpulso=false;                     //sera estado de subida
  }
  if (contador==2)
  {
    digitalWrite(vd,HIGH);
  }
  if (contador==4)
  {
    digitalWrite(am,HIGH);
  }
  if (contador==6)
  {
    digitalWrite(vm,HIGH);
  }  
  if (digitalRead(reset)==HIGH)
  {
    contador=0;
    digitalWrite(vd,LOW);
    digitalWrite(am,LOW);
    digitalWrite(vm,LOW);  
  }
}






