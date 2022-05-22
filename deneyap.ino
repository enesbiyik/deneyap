#include "deneyap.h"
#include <ESP32Servo.h>

#define SERVOPIN1 D0
#define Trig_Pin D14
#define Echo_Pin D15
#define Buzzer D1

Servo myservo;

int pos=0;
long sure;
long uzaklik;

void setup() {
  myservo.attach(SERVOPIN1);
  Serial.begin(115200);

  pinMode(Trig_Pin, OUTPUT);
  pinMode(Echo_Pin, INPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
 digitalWrite(Trig_Pin, LOW);
 delayMicroseconds(5); 
 digitalWrite(Trig_Pin, HIGH); 
 delayMicroseconds(10);
 digitalWrite(Trig_Pin, LOW); 

  sure = pulseIn(Echo_Pin, HIGH);

  uzaklik = sure/29.1/2;

  if(uzaklik < 10)
    digitalWrite(Buzzer, HIGH);
  if(uzaklik >= 10)
     digitalWrite(Buzzer, LOW);

  Serial.print("Uzaklık"); //uzaklık değeri serial monitör ekranına yazdırılıyor.
  Serial.print(uzaklik); 
  Serial.println("CM"); 

  pos = uzaklik*(180/40);
  myservo.write(pos);
  delay(5);
}
