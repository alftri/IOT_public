#define TRIGGER_PIN 5
#define ECHO_PIN 4
#define VELOCIDAD_SONIDO 0.034 // cm por segundo (340 m/s)

void setup(){
pinMode(TRIGGER_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
Serial.begin(9600);
}

void loop()
{
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  int duracion = pulseIn(ECHO_PIN, HIGH);
  int distancia = duracion * VELOCIDAD_SONIDO / 2;
  
  Serial.print(distancia);
  Serial.println(" cm");
  delay(500);
}