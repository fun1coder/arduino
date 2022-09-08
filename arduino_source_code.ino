//sensor libray
#include "max6675.h"
int soPin = 11;
int csPin = 2;
int sckPin = 3;
MAX6675 temp(sckPin, csPin, soPin);
int relay_on_f=4;
int relay_off_f=5;
int relay_on_r=6;
int relay_off_r=7;
//indication;
int fwd_on=8;
int rev_on=9;
int off=10;
void setup()
{ 
  Serial.begin(9600);
  digitalWrite(relay_on_f,HIGH);
  digitalWrite(relay_off_f,HIGH);
  digitalWrite(relay_on_r,HIGH);
  digitalWrite(relay_off_r,HIGH);
    
  
  pinMode(relay_on_f,OUTPUT);
  pinMode(relay_off_f,OUTPUT);
  pinMode(relay_on_r,OUTPUT);
  pinMode(relay_off_r,OUTPUT);
  pinMode(fwd_on,OUTPUT);
  pinMode(rev_on,OUTPUT);
  pinMode(off,OUTPUT);  
 
}
int temp_sig()
{   float t=temp.readCelsius();
    Serial.print("temp:");
   Serial.println(t);
 if(temp.readCelsius()>40)
 {
      Serial.print("temp:");
    Serial.println(t);
    return 1;
  }
 else
 {
  return 0;
 }
}



void loop()
{
  //forward direction on
  int n;
  digitalWrite(off,LOW);//indication
  delay(100);//indication
  digitalWrite(relay_on_f,LOW);
  delay(1000);
  digitalWrite(fwd_on,HIGH);//indication
  digitalWrite(relay_on_f,HIGH);
  delay(1000);
  for(int i=0;i<10;i++)
  {  
     delay(1000);
     if(temp_sig()==1)
       { 
          n=1;
       }  
     else 
       {
           n = 0;
       }
     if(n==1)
      { 
        n=0;
        digitalWrite(relay_off_f,LOW);
        delay(1000);
        break;
      }
      else
      {
        digitalWrite(relay_off_f,HIGH);
        delay(1000);
      }
  }
  // forward stoping
        digitalWrite(fwd_on,LOW);//indication
        delay(100);//indication
        digitalWrite(off,HIGH);//indication
        digitalWrite(relay_off_f,LOW);
        delay(10000);
        digitalWrite(relay_off_f,HIGH);
        delay(1000);

  //reverse direction on
  int l;
  digitalWrite(off,LOW);//indication
  delay(100);//indication
  digitalWrite(relay_on_r,LOW);
  delay(1000);
  digitalWrite(rev_on,HIGH);//indication
  digitalWrite(relay_on_r,HIGH);
  delay(1000);
  for(int i=0;i<10;i++)
  {  
     delay(1000);
     if(temp_sig()==1)
       { 
          l=1;
       }  
     else 
       {
           l = 0;
       }
     if(l==1)
      { 
        l=0;
        digitalWrite(relay_off_r,LOW);
        delay(1000);
        break;
      }
      else
      {
        digitalWrite(relay_off_r,HIGH);
        delay(1000);
      }
  }
  // reverse stoping
        digitalWrite(rev_on,LOW);//indication
        delay(100);//indication
        digitalWrite(off,HIGH);//indication
        digitalWrite(relay_off_r,LOW);
        delay(10000);
        digitalWrite(relay_off_r,HIGH);
        delay(1000);
  
  
  
  
}


