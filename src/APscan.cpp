/*
#include <Arduino.h>
#include <WiFi.h>

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  Serial.println("***** Boot/setup complete *****");
}

void loop() {
  Serial.println("*** Start Scan ***");
  int nets = WiFi.scanNetworks(false, true);    // These params set show_hidden == true
  Serial.print("Wifi networks detected: ");
  Serial.println(nets);

  for (int i = 0; i < nets; ++i) {              //Reason  for Post Increment is to Increment the value then Assign it to "i"
    //Print net details
    Serial.print(i + 1);
    Serial.print(":");
    Serial.print(WiFi.SSID(i));
    Serial.println(WiFi.RSSI(i));
    Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "   OPEN ":"   Password Required");
  }

  delay(2000);

}
*/