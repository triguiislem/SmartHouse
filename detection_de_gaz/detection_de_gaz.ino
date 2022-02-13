// C++ code
//
int motorPin = 7;
int ledg = 8;
int ledr = 9;
int detec = A0;
int buz = 11;


void setup()
{
  pinMode(motorPin, OUTPUT);
   pinMode(ledg, OUTPUT);
   pinMode(ledr, OUTPUT);
  pinMode(buz, OUTPUT);
   pinMode(detec, INPUT);
  Serial.begin(9600);
}

void loop()
{
  
  int  valeur= analogRead(detec);
 
  Serial.println(valeur);
    if (valeur>85){
       digitalWrite(ledr,HIGH);
      digitalWrite(buz,HIGH);
      digitalWrite(ledg,LOW);
  for (int i=0;i<=255;i++)
  {
    analogWrite(motorPin,i);
    //Serial.println(i);
    delay(50);
    
    
  } 
   
  delay(500);
  for (int i=255;i>=0;i--)
  {
    analogWrite(motorPin,i);
   // Serial.println(i);
    delay(50);
  
  }
  
    }
  else
  {
     digitalWrite(ledg,HIGH);
      digitalWrite(buz,LOW);
    digitalWrite(ledr,LOW);
  }
  
}
