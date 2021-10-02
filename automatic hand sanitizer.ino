#include <Servo.h>
int servoPin = 4;
Servo myServo;

int trigPin = 10;
int echoPin = 9;
float duration, cm;
int buzzer =7;
int red =6;
int green = 5;
int blue = 11;

void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    myServo.attach(servoPin);
    pinMode(buzzer, OUTPUT); 
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    cm = (duration / 2) / 29.1;
    Serial.print("in cm:");
    Serial.print(cm);
    Serial.println();
    delay(100);
  
  if(cm <=15)
  {
    myServo.write(90);
  delay(2000);
  myServo.write(0);
    Serial.println("USE SANITIZER & PREVENT CORONAVIRUS");
    digitalWrite(buzzer, HIGH);
    analogWrite(green, 255);
     analogWrite(red, 0);
     analogWrite(blue, 0);
    
    
      }
  else{
    digitalWrite(buzzer, LOW);
    
     analogWrite(green, 0);
     analogWrite(red, 255);
     analogWrite(blue, 0);
     delay(15);
    
  }
  delay(500);
   
}
