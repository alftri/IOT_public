  #include "Servo.h"

int servo_pin = D7;
int button_pin = D2;

Servo servo;
int button_count = 0; 
int speed = 1000;
int min_angle = 15;
int max_angle = 165;
int debounce_time = 300;
unsigned long button_time = 0;  
unsigned long last_button_time = 0;


void ICACHE_RAM_ATTR isr() {
  button_time = millis();
  if (button_time - last_button_time > debounce_time)
  {
    if (button_count < 3){
      button_count = button_count + 1;
    }
    else{
      button_count = 0;
      servo.write(min_angle);
    }
    last_button_time = button_time;
  }
}
 
void setup() 
{ 
  servo.attach(servo_pin);
  pinMode(button_pin, INPUT_PULLUP);
	attachInterrupt(button_pin, isr, FALLING);
  servo.write(min_angle);
} 


void loop() 
{ 
  if (button_count > 0){
    servo.write(min_angle);
    delay(speed / button_count);
    servo.write(max_angle);
    delay(speed / button_count);
  }
}



