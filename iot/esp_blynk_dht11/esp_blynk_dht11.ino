#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLTyetWUGI"
#define BLYNK_DEVICE_NAME "LED GOOGLE ASSISTANT"
#define BLYNK_AUTH_TOKEN "0JXRA4-xeiEmIbHver7mAUA8ihwj-jRx"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11  
#define dht_dpin 14
DHT dht(dht_dpin, DHTTYPE); 
BlynkTimer timer;

float t;                                   // Declare the variables 
float h;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "WifiName";
char pass[] = "Pass";

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(2000, sendUptime);
}

void sendUptime()
{
  
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Current humidity = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(t); 
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  
}

void loop()
{
  Blynk.run();
  timer.run();
}

