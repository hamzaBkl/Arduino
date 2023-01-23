#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensorValue = 0;
int percentValue = 0;
int buz = 13;
int sensor = A0;

void setup()
{
  Serial.begin(9600);
  pinMode(buz, OUTPUT);
  pinMode(sensor, INPUT);
  lcd.begin();

	// Turn on the blacklight and print a message.
	lcd.backlight();
	lcd.print("Soil Moisture");
  delay(2000);
}

void loop()
{
  sensorValue = analogRead(sensor);
 
  
  
  percentValue = map(sensorValue, 1023, 200, 0, 100);
  Serial.print("\nPercentValue: ");
  Serial.print(percentValue);
  Serial.print("%");
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture :");
  
  lcd.setCursor(6, 1);  

  lcd.print(percentValue);
  lcd.print("%");
      if(sensorValue > 680){
  Buzzer()   ;      
  } 
  delay(1000);
  lcd.clear();
  
}

  void Buzzer()
 {
 digitalWrite(buz,HIGH);
 delay(500);
 digitalWrite(buz, LOW);
 delay(500);
 }
