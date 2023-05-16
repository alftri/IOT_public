#include "config.h"
#include <DHT.h> //This library you can add via Include Library > Manage Library >
#include <Wire.h>  // This library is already built in to the Arduino IDE
#include <LiquidCrystal_I2C.h> //This library you can add via Include Library > Manage Library > 
//LiquidCrystal_I2C lcd(0x3F, 16, 2);
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DHTPIN 3         //define as DHTPIN the Pin 3 used to connect the Sensor
#define DHTTYPE DHT11    //define the sensor used(DHT11)
DHT dht(DHTPIN, DHTTYPE);//create an instance of DHT

AdafruitIO_Feed *humedad = io.feed("humedad");
AdafruitIO_Feed *temperatura = io.feed("temperatura");

float hum_value, temp_value;  // Values read from sensor
unsigned long previousMillis = 0;        // will store last temp was read
const long interval = 2000;              // interval at which to read sensor
 

void setup() {
  lcd.init();   // initializing the LCD
  lcd.backlight();
  Serial.begin(9600);
  dht.begin(); // initialize temperature sensor

  while(! Serial);
  Serial.print("Connecting to Adafruit IO");
  io.connect();
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println(io.statusText());
}

void loop() {
  io.run();
  gettemperature();
  lcd.setCursor(0, 0);
  String hs="Humidity: "+String((int)hum_value)+" % ";
  String ts="Temp: "+String((int)temp_value)+" C ";
  lcd.setCursor(0, 0);
  lcd.print(ts);
  lcd.setCursor(0, 1);
  lcd.print(hs);
  temperatura->save(temp_value);
  humedad->save(hum_value);
  delay(10000);
}

void gettemperature() {
  unsigned long currentMillis = millis();
 if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;   
    hum_value = dht.readHumidity();          // Read humidity (percent)
    temp_value = dht.readTemperature(false);     // Read temperature as Celsius
    if (isnan(hum_value) || isnan(temp_value)) {
      hum_value=0;
      temp_value=0;
      Serial.println("Failed to read from DHT sensor!");
      return;
    }
  }
}