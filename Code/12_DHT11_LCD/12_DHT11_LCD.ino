/* 
DHT Weather server with display integrated for NodeMCU esp8266 and 1602A LCD
Please connect 1602A using I2C backpack.
If you feel display is not showing anything, please take a screwdriver and update contrast 
using I2C potentiometer in back of LCD

LCD config
  SDA pin - D2
  SCL pin - D1
  VCC Pin - 5v
  
Sensor Config
  Sensor Data pin - RX
  Sensor VCC - 3.3 volt pin
*/

#include <DHT.h> //This library you can add via Include Library > Manage Library >
#include <Wire.h>  // This library is already built in to the Arduino IDE
#include <LiquidCrystal_I2C.h> //This library you can add via Include Library > Manage Library > 
//LiquidCrystal_I2C lcd(0x3F, 16, 2);
LiquidCrystal_I2C lcd(0x27, 16, 2);


#define DHTPIN 3         //define as DHTPIN the Pin 3 used to connect the Sensor
#define DHTTYPE DHT11    //define the sensor used(DHT11)
DHT dht(DHTPIN, DHTTYPE);//create an instance of DHT

float humidity, temp_f;  // Values read from sensor
unsigned long previousMillis = 0;        // will store last temp was read
const long interval = 2000;              // interval at which to read sensor
 
void setup(void)
{
  lcd.init();   // initializing the LCD
  lcd.backlight();
  Serial.begin(115200);
  dht.begin(); // initialize temperature sensor
}
 
void loop(void)
{
  gettemperature();
  lcd.setCursor(0, 0);
  String hs="Humidity: "+String((int)humidity)+" % ";
  String ts="Temp: "+String((int)temp_f)+" C ";
  lcd.setCursor(0, 0);
  lcd.print(ts);
  lcd.setCursor(0, 1);
  lcd.print(hs);
  
} 

void gettemperature() {
  unsigned long currentMillis = millis();
 if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;   
    humidity = dht.readHumidity();          // Read humidity (percent)
    temp_f = dht.readTemperature(false);     // Read temperature as Celsius
    if (isnan(humidity) || isnan(temp_f)) {
      humidity=0;
      temp_f=0;
      Serial.println("Failed to read from DHT sensor!");
      return;
    }
  }
}