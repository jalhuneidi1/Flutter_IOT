#include "Network.h"


#define WIFI_SSID "{wifi name}"
#define WIFI_PASSWORD "{wifi password}"
#define API_KEY "AIzaSyDGHw6KPolUn1CXhwUXLnWkIXF9EXBrctA"
#define FIREBASE_PROJECT_ID "{firebase project ID}"
#define USER_EMAIL "testing@abc.com"
#define USER_PASSWORD "ABCD1234"


static Network *instance = NULL;

Network::Network(){
  instance = this;
}

void WiFiEventConnected(WiFiEvent_t event, WiFiEventInfo_t info){
  Serial.println("WIFI CONNECTED! BUT WAIT FOR THE LOCAL IP ADDR");
}

void WiFiEventGotIP(WiFiEvent_t event, WiFiEventInfo_t info){
  Serial.print("LOCAL IP ADDRESS: ");
  Serial.println(WiFi.localIP());
  instance->firebaseInit();
}

void WiFiEventDisconnected(WiFiEvent_t event, WiFiEventInfo_t info){
  Serial.println("WIFI DISCONNECTED!");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}


void Network::initWiFi() {
  WiFi.disconnect();
  WiFi.onEvent(WiFiEventConnected, ARDUINO_EVENT_ETH_CONNECTED);
  WiFi.onEvent(WiFiEventGotIP, ARDUINO_EVENT_ETH_GOT_IP);
  WiFi.onEvent(WiFiEventDisconnected, ARDUINO_EVENT_ETH_DISCONNECTED);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}


void Network::firebaseInit(){
  config.api_key = API_KEY;

  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  Firebase.begin(&config, &auth);
}

void Network::firestoreDataUpdate(double temp, double humi){
  if(WiFi.status() == WL_CONNECTED && Firebase.ready()){
    String documentPath = "House/Room_1";

    FirebaseJson content;

    content.set("fields/temperature/doubleValue", String(temp).c_str());
    content.set("fields/humidity/doubleValue", String(humi).c_str());

    if(Firebase.Firestore.patchDocument(&fbdo, FIREBASE_PROJECT_ID, "", documentPath.c_str(), content.raw(), "temperature,humidity")){
      Serial.printf("ok\n%s\n\n", fbdo.payload().c_str());
      return;
    }else{
      Serial.println(fbdo.errorReason());
    }

    if(Firebase.Firestore.createDocument(&fbdo, FIREBASE_PROJECT_ID, "", documentPath.c_str(), content.raw())){
      Serial.printf("ok\n%s\n\n", fbdo.payload().c_str());
      return;
    }else{
      Serial.println(fbdo.errorReason());
    }
  }
}