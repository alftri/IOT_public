//defino los parametros del sensor de ultrasonidos
#define TRIGGER_PIN 14 //D5
#define ECHO_PIN 12 //D6
#define VELOCIDAD_SONIDO 0.034 // cm por segundo (340 m/s)
#define BUZZER 2

//defino los parametros de la pantalla
#define LCD_COLS 16
#define LCD_ROWS 2
#define SDA_PIN 4 (D2)  
#define SCL_PIN 5 (D1)
#define LCD_ADDRESS 0x27
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLS, LCD_ROWS);  

void setup(){
pinMode(TRIGGER_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
pinMode(BUZZER, OUTPUT);
Serial.begin(9600);
lcd.init();
lcd.backlight();
}

void loop()
{
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  tone(BUZZER,500);
  
  int duracion = pulseIn(ECHO_PIN, HIGH);
  int distancia = duracion * VELOCIDAD_SONIDO / 2;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(distancia);
  lcd.setCursor(0, 1);
  lcd.print("cm");
  delay(1000);
  Serial.print(distancia);
  Serial.println(" cm");
  delay(500);
}