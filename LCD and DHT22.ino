int ButtonPin = 8;
//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE    DHT22

DHT_Unified dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


int counter = 0;

void setup()
{
  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  pinMode(ButtonPin, INPUT);
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Please Wait");
  delay(992);
  lcd.clear();
  lcd.print("Please Wait.");
  delay(992);
  lcd.clear();
  lcd.print("Please Wait..");
  delay(992);
  lcd.clear();
  lcd.print("Please Wait...");
  delay(992);
  lcd.clear();
    lcd.print("Please Wait");
  delay(992);
  lcd.clear();
  lcd.print("Please Wait.");
  delay(992);
  lcd.clear();
  lcd.print("Please Wait..");
  delay(992);
  lcd.clear();
  lcd.print("Please Wait...");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DHT22");
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor);
}


void loop()
{
   if (ButtonPin > 1)
   {
     lcd.backlight();
   } 
   else {
     lcd.noBacklight();
   }
  
  delay(100);

  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (!isnan(event.temperature)) {
      lcd.setCursor(0,1);
      lcd.print(event.temperature);
      lcd.print(F("\xdf"));
      lcd.print(F("C"));
  }
  dht.humidity().getEvent(&event);
  if (!isnan(event.relative_humidity)) {
      lcd.setCursor(0,2);
      lcd.print(event.relative_humidity);
      lcd.print(F("%"));
  }
}