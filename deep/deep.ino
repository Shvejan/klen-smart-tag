#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "klen-d13b9.firebaseio.com"
//u#define FIREBASE_AUTH "AIzaSyD6GrR87DLKCUIh1azlJpMW4he-KdocSik"
const char* ssid     = "Shivatejan4g";
const char* password = "@shivatejan1";


void setup() {
Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
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
    while(!Firebase.available());
}

  
void loop() {
  
  digitalWrite(12,HIGH);
  delay(1000);
  digitalWrite(12,LOW);
  ESP.deepSleep(3e6);
  
}
