#include<Arduino.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "klen-d13b9.firebaseio.com"
//#define FIREBASE_AUTH "AIzaSyD6GrR87DLKCUIh1azlJpMW4he-KdocSik"

#ifndef STASSID
#define STASSID "IOT-SNiST"
#define STAPSK  "snist@iot123"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

void setup() {
  Serial.begin(115200);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);


  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST);
}

void loop() {
  int x= Firebase.getInt("KlenData/number")+1;
  while(!Firebase.success());
  Firebase.setInt("KlenData/number", x);
  while(!Firebase.success());
  Serial.println(x);
  ESP.deepSleep(8000000);
  ESP.deepSleep(8000000);
}
