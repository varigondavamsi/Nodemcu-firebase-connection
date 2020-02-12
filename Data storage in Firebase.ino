// code to send data to fire base


#include <ESP8266WiFi.h>    //for node mcu
#include <FirebaseArduino.h> // to connect node mcu and firebase
#define FIREBASE_HOST "***********.firebaseio.com"  // appdata base, it can be found in firebase database, change it to real time database
#define FIREBASE_AUTH "***************************" // copy the secret code from the service account settings in firebase
#define WIFI_SSID "wifi id" // enter the wifi address
#define WIFI_PASSWORD "password" // enter it's password  

  
  String Enroll = String("data") + String(id); // adding these two everytime creates a new child in fire base
  
  Firebase.pushString("fingerprint database" ,(Enroll));  // To get multiple entries in the database

  if (Firebase.failed())   // to find any error in uploading the code
  {
    Serial.println(Firebase.error());
  }
  Serial.println("sent to online database");    
}
