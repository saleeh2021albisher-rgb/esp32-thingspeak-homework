#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

const char* STUDENT_NAME = "Saleh Albisher";
const char* UNIVERSITY_ID = "12217436";
const char* THINGSPEAK_WRITE_API_KEY = "M0W0IL3JLNAHFBPK";

const char* WIFI_SSID = "Wokwi-GUEST";
const char* WIFI_PASS = "";

#define DHT_PIN 15        
#define DHT_TYPE DHT22   

const int SEND_INTERVAL_MS = 20000;  

DHT dht(DHT_PIN, DHT_TYPE);
int lastSend = 0;

void connectWiFi() {
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi connected" );
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  connectWiFi();
  Serial.printf("Student: %s | University ID: %s\n", STUDENT_NAME, UNIVERSITY_ID);
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) connectWiFi();

  if (millis() - lastSend >= SEND_INTERVAL_MS || lastSend == 0) {
    lastSend = millis();

    float t = dht.readTemperature();
    float h = dht.readHumidity();

    if (isnan(t) || isnan(h)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

   
    String url = "http://api.thingspeak.com/update?api_key=" + String(THINGSPEAK_WRITE_API_KEY) +
                 "&field1=" + String(t, 1) +
                 "&field2=" + String(h, 1) +
                 "&status=ID_" + String(UNIVERSITY_ID);

    HTTPClient http;
    http.begin(url);
    int code = http.GET();
    String entry = http.getString();  
    http.end();

    Serial.printf("[ID %s] Temp: %.1f C | Hum: %.1f %% | HTTP %d | entry #%s\n",
                  UNIVERSITY_ID, t, h, code, entry.c_str());
  }
}
