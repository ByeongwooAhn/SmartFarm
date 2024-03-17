#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
#define Relay_5v 6

DHT dht(DHTPIN, DHTTYPE);


float hum[10] = {85, 84, 66, 84, 77, 88, 85, 76, 72, 82};
float temp[10] = {16.2, 17.4, 15.11, 14, 14.6, 14.3, 14.9, 18.6, 19.6, 19.6};
char week[20] = {"수", "목", "금", "토", "일", "월", "화", "수", "목", "금"};
char date[100] = {"10월25일", "10월26일", "10월27일", "10월28일", "10월29일", "10월30일", "10월31일", "11월1일", "11월2일", "11월3일"};

void setup() {
  pinMode(Relay_5v, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  //float hum = dht.readHumidity();
  //float temp = dht.readTemperature();
  //float number = random(50, 70);

  for(int i = 0; i < 10; i++){
    Serial.println(date);
    Serial.println(week);
    Serial.println(date);
  }
  delay(1000);
  Serial.println(number);

  if(number >= 55) {
    digitalWrite(Relay_5v, HIGH);
    
    while(number > 55) {
      number -= 4;
      Serial.print("////////////////");
      Serial.println(number);
      delay(1000);
    }
  }
  
  number -= 4;
  
  Serial.print("////////////////");
  Serial.println(number);
  digitalWrite(Relay_5v, LOW);

  /*if(temp >= 38 || hum >= 70) {
    digitalWrite(Relay_5v, HIGH);
  }
  else {
    digitalWrite(Relay_5v, LOW);
  }*/
  
  
  /*Serial.print("Humidity: ");
  Serial.println(hum);
  Serial.print("Temp: ");
  Serial.println(temp);
  delay(2000); //딜레이 2초*/
}
