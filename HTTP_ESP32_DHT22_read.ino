//ESP32 + DHT22 + HTTP + Thingspeak (Data Read/ Write)
//FULL CODE: READ DATA FROM THINGSPEAK
#include <WiFi.h>
#include <HTTPClient.h>

//WiFi credentials 
#define WIFI_SSID     "Sumon"
#define WIFI_PASSWORD "01717796447"

String readApiKey = "Y4AL39YBBKAKN43T"; // YOUR_READ_API_KEY
int channelID =  3168683; //YOUR_CHANNEL_ID

// Setup function
void setup() {
  Serial.begin(115200);

//WiFi initialization
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
}

// Main function
void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

String url = "http://api.thingspeak.com/channels/" + 
                 String(channelID) + "/feeds.json?api_key=" + 
                 readApiKey + "&results=1";

 http.begin(url);
 int httpCode = http.GET();

 if (httpCode > 0) {
      Serial.println("ThingSpeak Response:");
      String payload = http.getString();
      Serial.println(payload);
    } else {
      Serial.println("Error on HTTP request");
    }

    http.end();
  }

  delay(15000);
}


