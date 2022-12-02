#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4 // pino D2
#define DHTTYPE DHT11 // DHT 11
#define rele 13
LiquidCrystal_I2C lcd(0x27, 16, 2);//
int SensorTempPino=0;
DHT dht(DHTPIN, DHTTYPE);
 
void setup() 
{
  pinMode(13,OUTPUT);
  pinMode(15,OUTPUT);
  

  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();

  Wire.begin(2,0); //SDA Pino D4,SCL D3
  lcd.init();   // initializing the LCD
  lcd.backlight(); // Enable or Turn On the backlight 
  //lcd.setCursor(0,1);
}
 
void loop() 
{
  // A leitura da temperatura e umidade pode levar 250ms!
  // O atraso do sensor pode chegar a 2 segundos.
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // testa se retorno é valido, caso contrário algo está errado.
  if (isnan(t) || isnan(h)){
    Serial.println("Failed to read from DHT");
  } 
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Temperatura: ");
    lcd.print(t);
    lcd.println(" *C");
    lcd.setCursor(0,1);
    lcd.print("Umidade: ");
    lcd.print(h);
    lcd.print(" %");
    
  }

  delay(200);
}