#include <Servo.h>

#define echo 6
#define trig 7
#define kirmizi 3
#define yesil 4
#define mavi 5
#define alarm 8

long zaman;
float cm;

Servo motor;

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(kirmizi,OUTPUT);
  pinMode(yesil,OUTPUT);
  pinMode(mavi,OUTPUT);
  pinMode(alarm,OUTPUT);
  motor.attach(9);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(kirmizi,LOW);
  digitalWrite(yesil,LOW);
  digitalWrite(mavi,LOW);
  
  for(int i=0 ;i<180 ;i++){
    motor.write(i);
    delay(20);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);

    zaman = pulseIn(echo,HIGH);
    cm = zaman/58.2;
    if(cm < 20){
      
      Serial.print(i);
      Serial.print(" derece yönünde cisim algılandı.....");
      Serial.print(cm);
      Serial.print("cm uzaklıkta.....");
      Serial.println(" ");
      delay(20);
      for(int j=0 ; j<20 ; j++ ){
          digitalWrite(alarm,HIGH);
          digitalWrite(kirmizi,HIGH);
          digitalWrite(yesil,LOW);
          digitalWrite(mavi,LOW);
          delay(100);
          digitalWrite(alarm,LOW);
          digitalWrite(kirmizi,LOW);
          digitalWrite(yesil,LOW);
          digitalWrite(mavi,LOW);
          delay(100);          
        }
      
      
    }
    else{
      digitalWrite(kirmizi,LOW);
      digitalWrite(yesil,HIGH);
      digitalWrite(mavi,LOW);
      Serial.println("Güvenli");
      delay(5);
      
    }
    
  }
    
  for(int i=180 ;i>0 ;i--){
    motor.write(i);
    delay(20);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);

    zaman = pulseIn(echo,HIGH);
    cm = zaman/58.2;
    if(cm < 20){
            
      Serial.print(i);
      Serial.print(" derece yönünde cisim algılandı.....");
      Serial.print(cm);
      Serial.print("cm uzaklıkta.....");
      Serial.println(" ");
      delay(20);
      for(int j=0 ; j<20 ; j++ ){
        digitalWrite(alarm,HIGH);
        digitalWrite(kirmizi,HIGH);
        digitalWrite(yesil,LOW);
        digitalWrite(mavi,LOW);
        delay(100);
        digitalWrite(alarm,LOW);
        digitalWrite(kirmizi,LOW);
        digitalWrite(yesil,LOW);
        digitalWrite(mavi,LOW);
        delay(100);          
        }
      
    }
    else{
      digitalWrite(kirmizi,LOW);
      digitalWrite(yesil,HIGH);
      digitalWrite(mavi,LOW);
      Serial.println("Güvenli");
      delay(50);
      
    }
    
  }  
}
