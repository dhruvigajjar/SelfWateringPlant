#include <Servo.h>
int spin=11;
int angle,i;
Servo servoLeft;

int MS1=0;
int MS2=0;
int ML1,ML2;

void islevel1();
void islevel2();
void setup() 
{
  pinMode(4,OUTPUT);
  Serial.begin(9600);
  servoLeft.attach(spin);
  servoLeft.write(180);
}

void loop() 
{
  
  for(i=0; i<=180; i++)
  {
    servoLeft.write(i);
  }
  delay(3000);
  islevel1();
  delay(3000);
  
 
  for(i=180; i>=0; i--)
  {
    servoLeft.write(i);
  }
  delay(3000);
  islevel2();
  delay(3000);
  
  
 
}




void islevel1()
{
  MS1=analogRead(A0);
  delay(100);
  ML1=map(MS1,0,1023,100,0);
  Serial.println("ML1");
  Serial.println(ML1);
  
 if(ML1<30 && ML1>=0)  
 {
  digitalWrite(4,LOW);
  delay(3000);
  
  digitalWrite(4,HIGH);
  delay(1000);
  
 }
 delay(1000);
 
}


void islevel2()
{
  MS2=analogRead(A1);
  delay(100);
  ML2=map(MS2,0,1023,100,0);
  Serial.println("ML2");
  Serial.println(ML2);
 
 if(ML2<30 && ML2>=0)  
 {
   digitalWrite(4,LOW);
   delay(3000);
  
  digitalWrite(4,HIGH);
  delay(1000);
  
 }
  delay(1000);
 
}

