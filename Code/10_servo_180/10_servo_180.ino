  #include "Servo.h"

int servo_pin = D7;  // for ESP8266 microcontroller

Servo servo;
 
void setup() 
{ 
  servo.attach(servo_pin);
  Serial.begin(9600);
  servo.write(0);
} 
  
void loop() 
{ 
  servo.write(0);
  delay(1000);
  servo.write(45);
  delay(1000);
  servo.write(90);
  delay(1000);
  servo.write(135);
  delay(1000);
  servo.write(180);
  delay(1000);
}