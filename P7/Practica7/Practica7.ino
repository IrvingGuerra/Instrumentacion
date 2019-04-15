#define RS 2
#define EN 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7

//Definimos variable donde entrara el sensor
#define Sensor A7 //Recibira valores de 0 a 5 Volts

float SensorValue = 0;

#include <LiquidCrystal.h>
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  pinMode(Sensor,INPUT);
  lcd.begin(16, 2);
  lcd.setCursor (0,0); 
  lcd.print("SensorTemp");
  lcd.setCursor(0, 1);  
  lcd.print("Practica 6");
  delay(300);
  lcd.clear();
}

void loop() {
  SensorValue = (analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor)+analogRead(Sensor))/20;
  SensorValue = ((SensorValue * 100.0)/1024.0);  
  lcd.print("Valor salida:"); 
  lcd.setCursor(0, 1); 
  lcd.print(SensorValue);
  lcd.print(" Ohms");
  delay(40);
  lcd.clear();
}
