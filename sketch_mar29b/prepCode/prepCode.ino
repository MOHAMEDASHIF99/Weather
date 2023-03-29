#include<Firebase_ESP_Client.h>
#include<Wire.h>
#include <ESP8266WiFi.h>
char* WIFI_SSID="POCO F3 GT";
char* WIFI_PASSWORD="ashif211099";

#define dbURL "https://weather-c54c3-default-rtdb.firebaseio.com/"

FirebaseData fbo;
FirebaseAuth auth;
FirebaseConfig conf;

void connectWifi(char* WIFI_SSID,char* WIFI_PASSWORD){
   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected.");

}

void connectFireBase(){
  //preparing config
  conf.api_key="AIzaSyDwWeKjpNJIpwp8ZHaRZQRXtrFl4XHo6Cs";
  conf.database_url=dbURL;

  //Setting authorizor
  auth.user.email="mohamedashif99@gmail.com";

  //begin connetion
  Firebase.begin(&conf,&auth);
  Serial.print("Firebase connection established");
}

void setup(){
  //setting up Serial
  Serial.begin(9600);
  
  //Connect to wifi
  connectWifi(WIFI_SSID,WIFI_PASSWORD);

  //connect firebase
  connectFireBase();
  
}

void loop(){

  
}
