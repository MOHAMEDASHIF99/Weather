#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include "wifiCon.cpp"
#define FIREBASE_HOST "https://weather-c54c3-default-rtdb.firebaseio.com/" // Firebase host
#define FIREBASE_AUTH "SS3G1txBLRXaxSuDN6PFneFfnHMNKDXcm1irXgBd" //Firebase Auth code
#define WIFI_SSID "POCO F3 GT" //Enter your wifi Name
#define WIFI_PASSWORD "ashif211099" // Enter your password
int fireStatus = 0;
void setup() {
  Serial.begin(9600);
  pinMode(D1, OUTPUT);
  
  //Connects to wifi
  connectWifi(WIFI_SSID,WIFI_PASSWORD);
  
  //Firebase connection code
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setString("LED_STATUS", 0);
}
void loop() {
  fireStatus = Firebase.getInt("LED_STATUS");
  if (fireStatus == 1) {
    Serial.println("Led Turned ON");
    digitalWrite(D1, HIGH);
  }
  else if (fireStatus == 0) {
    Serial.println("Led Turned OFF");
    digitalWrite(D1, LOW);
  }
  else {
    Serial.println("Command Error! Please send 0/1");
  }
}
