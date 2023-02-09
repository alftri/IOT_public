# define BUZZER 4
# define FRECUENCIA 500 

void setup() {
   pinMode(TRIGGER_PIN, OUTPUT); 
}

void loop() {
  tone(BUZZER, FRECUENCIA);
  delay(1000);
  tone(BUZZER, 0); 
}