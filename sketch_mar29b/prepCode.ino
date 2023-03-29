#include <ESP8266WiFi.h>
#define WIFI_SSID "POCO F3 GT" //Enter your wifi Name
#define WIFI_PASSWORD "ashif211099" // Enter your password


void connectWifi(char* SSID,char* PASS){
   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected.");

}
