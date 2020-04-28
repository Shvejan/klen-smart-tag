
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "klen-d13b9.firebaseio.com"

const char* ssid     = "*";
const char* password = "12345678";
int p=12;
void setup() {
  Serial.begin(115200);
  pinMode(p,OUTPUT);
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
  if(x=="\"1\"")
  {
    Firebase.getString("KlenData/app");
    while(!Firebase.success());
    Serial.println(x);
    digitalWrite(p,HIGH);
    delay(5000);
    digitalWrite(p,LOW);
    Firebase.setString("KlenData/app","\"0\"" );
  }
  Serial.println("sleepin");
  ESP.deepSleep(4000000);
  ESP.deepSleep(4000000);
 
}
