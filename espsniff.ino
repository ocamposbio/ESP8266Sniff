#include <ESP8266WiFi.h>
#include <ESP8266Sniffer.h>

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Start packet sniffing
  ESP8266Sniffer.enable();
  ESP8266Sniffer.onPacket([](const uint8_t* buffer, uint16_t length) {
    // Print the packet data
    Serial.print("Packet: ");
    for (int i = 0; i < length; i++) {
      Serial.print(buffer[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  });
}
