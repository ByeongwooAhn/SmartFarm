#include "DHT.h"
#include "Servo.h"
#define DHTPIN 2
#define DHTTYPE DHT22
#define Relay_5v 6

Servo servo;
DHT dht(DHTPIN, DHTTYPE);

float number = 0;
int value = 0;

void setup() {
  pinMode(Relay_5v, OUTPUT);
  servo.attach(7);
  pinMode(13, OUTPUT);
  randomSeed(digitalRead(2));
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
  float a = NULL;
  int t = 0;
  float goal = 80;

  if(Serial.available()) {
   a = Serial.parseInt();
   Serial.print("현재 습도: ");
   Serial.println(a);
   Serial.print("목표값: ");
   Serial.println(goal);
  }

  if(a != NULL) {
   if(a < 80) {
    while(a < 80) {
      value += 90;
      a += 0.27;
      Serial.println(a);
      delay(1000);
    }  
  }

  if(a > 80) {
    while(a > 80) {
    digitalWrite(13, HIGH);
    a -= 0.08;
    digitalWrite(Relay_5v, HIGH);
    a -= 0.13;
    Serial.println(a);
    delay(1000);
    }
  }

  digitalWrite(Relay_5v, LOW);
  digitalWrite(13, LOW);
  
  Serial.println(a); 
  
  Serial.print("Humidity: ");
  Serial.println(hum);
  Serial.print("Temp: ");
  Serial.println(temp);
  }
}
