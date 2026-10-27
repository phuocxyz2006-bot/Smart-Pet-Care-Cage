#include <HX711_ADC.h>
#include <Servo.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define dhtpin 4
#define dhttype DHT11 
DHT dht(dhtpin,dhttype);
LiquidCrystal_I2C lcd(0x27,16,2);
HX711_ADC LoadCell(7, 8);

unsigned long lastDisplayChange = 0;
int displayMode = 0;  
int activityCount = 0;
int lastPirState = LOW;
int servo = 10;
int sensorVCC = 5;  
int buzzer = 9; 
int sensorPin = A2; 
int sensorSR501 = 2;
int led = 12;
int led2 = 13;
bool daQuay = false;
static unsigned long t = 0;
Servo myservo;
void setup(){
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  pinMode(sensorVCC, OUTPUT);
  digitalWrite(sensorVCC, LOW);
  pinMode(buzzer, OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(sensorSR501,INPUT);

  myservo.attach(servo);
  LoadCell.begin(); 
  LoadCell.start(2000); 
  LoadCell.setCalFactor(-420.0); 

}
void loop(){
{  if(digitalRead(sensorSR501) == HIGH){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
}
{
int pirState = digitalRead(sensorSR501);
if(pirState == HIGH){
  digitalWrite(led,HIGH);
  if(lastPirState == LOW){ 
    activityCount++; 
  }
} else {
  digitalWrite(led,LOW);
}
lastPirState = pirState;
unsigned long now = millis();
if(now - lastDisplayChange >= 1000){
  lastDisplayChange = now;
  displayMode = 1 - displayMode; 
}
lcd.clear();
if(displayMode == 0){
  float doam = dht.readHumidity();
  float nhietdo = dht.readTemperature();
  lcd.setCursor(0,0); lcd.print("do am = "); lcd.print(doam);
  lcd.setCursor(0,1); lcd.print("nhiet do = "); lcd.print(nhietdo);
} else {
  lcd.setCursor(0,0); lcd.print("Hoat dong pet:");
  lcd.setCursor(0,1); lcd.print(activityCount);
}

}
{digitalWrite(sensorVCC, HIGH);
  delay(10); 

  int value = analogRead(sensorPin);
  Serial.print("Nuoc: ");
  Serial.println(value);
  digitalWrite(sensorVCC, LOW);


  if (value < 15) {
    digitalWrite(led2, HIGH);
    for(int i = 0; i < 3; i++){
    tone(buzzer, 2000);   
    delay(200);
    noTone(buzzer);
    delay(200);
  } 
    delay(3000);
  }
  else {
    digitalWrite(led2, LOW);
    noTone(buzzer);
  }

  delay(1000);}

 {

  LoadCell.update();
  float i = LoadCell.getData();
  Serial.println(i);

 if (i <= 0 && daQuay == false) {
  myservo.write(180);
  daQuay = true;
}
if (i > 0.5 && daQuay == true) {
  myservo.write(90);
  daQuay = false;
}

}
  

}
