#include<LiquidCrystal.h>
LiquidCrystal lcd(5,6,7,8,9,10);
int redLed = 12;
int greenLed = 13;
int buzzer = 11;
int sensormq= A0;
// Your threshold value
int sensorThres = 150;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensormq, INPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}
void loop() {
  int analogSensor = analogRead(sensormq);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 3000, 300);
    if (Serial.available())
    {
      delay(100);
      lcd.clear();
      lcd.write(Serial.read());
    }
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
  delay(100);

  
}
