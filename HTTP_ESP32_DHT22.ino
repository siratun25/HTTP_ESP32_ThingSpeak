
//ESP32 + DHT22 + HTTP + Thingspeak (Data Read/ Write)
//FULL CODE: SEND DATA TO THINGSPEAK
#include <WiFi.h>
#include "DHT.h"

//WiFi credentials
#define WIFI_SSID     "*******"
#define WIFI_PASSWORD "**************"

// DHT22 sensor initialization
#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// ThingSpeak details
String apiKey = "**************";  //YOUR_WRITE_API_KEY
String server = "api.thingspeak.com";
int channelID = ********;  // YOUR_CHANNEL_ID - number, no quotes

WiFiClient client;

// Setup function
void setup() {
  Serial.begin(115200);
  dht.begin();

  // WiFi initialization
  Serial.println("Connecting to WiFi...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

Serial.println("\nWiFi Connected!");
}

// Main function
void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

 Serial.println("Sending data to ThingSpeak...");

 if (client.connect(server.c_str(), 80)) {  // 80 - HTTP default port,, server.c_str() → server name (e.g., api.thingspeak.com)

    String url = "/update?api_key=" + apiKey +
                 "&field1=" + String(temperature) +
                 "&field2=" + String(humidity);

    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + server + "\r\n" +
                 "Connection: close\r\n\r\n");

    // Read response
    while (client.available() == 0);
    while (client.available()) {
      String line = client.readStringUntil('\n');
      Serial.println(line);
    }
  }

  client.stop();
  Serial.println("Data sent!");

  delay(20000);  // ThingSpeak minimum update rate: 15 sec+
}
 


