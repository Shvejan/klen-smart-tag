
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "klen-d13b9.firebaseio.com"

const char* ssid     = "Shivatejan4g";
const char* password = "@shivatejan1";

void setup() {
  Serial.begin(115200);
  pinMode(D3, OUTPUT);
  Serial.println("Connecting to ");
  //WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
   delay(250);
  }
  Serial.println("WiFi connected");
  Firebase.begin(FIREBASE_HOST);
}
void loop() {
  String x= Firebase.getString("KlenData/app");
  while(!Firebase.success());
  Serial.println(x);
  digitalWrite(D3,HIGH);
  Serial.println("onnnn");
  delay(5000);
  digitalWrite(D3,LOW);
  ESP.deepSleep(8000000);
}
