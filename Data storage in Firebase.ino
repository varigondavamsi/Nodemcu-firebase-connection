/* The main code is created by K. Suwatchai (Mobizt)
 * This is just a snip of the complete code
 */
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "***********.firebaseio.com"  // don't add https, the link is found in real time database
#define FIREBASE_AUTH "***************************" // copy the secret code from the service account settings in firebase
#define WIFI_SSID "wifi id" // enter the wifi address
#define WIFI_PASSWORD "password" // enter it's password  
//Define FirebaseESP8266 data object
FirebaseData firebaseData;
void setup()
{
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
 }
void loop()
{
  for (int i = 0; i < 10; i++)
  {
    //Also can use Firebase.set instead of Firebase.setDouble
    if (Firebase.setDouble(firebaseData,"/path (i,i+1))){//change the path as per requirement
      Serial.println("PASSED");
    }
    else{
      Serial.println("FAILED");
      Serial.println("REASON: " + firebaseData.errorReason());
    }
   delay(60000);
  }
}
