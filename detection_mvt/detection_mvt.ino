// C++ code
//
int led=8;
int capteur=A0;
int capteur1=7;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(capteur,INPUT);
   pinMode(capteur1,INPUT);
  
}

void loop()
{
  
 int  valeur= analogRead(capteur);
 int  valeur1= digitalRead(capteur1);
  
    if (valeur<200 and valeur1==HIGH){
    digitalWrite(led,HIGH);
}
  else
  {
  digitalWrite(led, LOW);
  }
  
}
