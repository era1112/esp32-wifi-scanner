#include <Arduino.h>
#include <WiFi.h>
#define SCAN_RATE 2000      //Time to wait between scans (in ms)

/* 
  Entry Point. 
  Establishes serial connection, tests wifi modem, sends confirmation message to console.
*/
void setup() 
{
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  Serial.println("***** Boot/setup complete *****");
}

/* 
  Called by framework after setup() completes, runs in a loop until device termination. 
  Scans for wifi networks, delivers reports over serial
*/
void loop() 
{
  Serial.println("*** Start Scan ***");
  
  // Returns number of networks found. The params include hidden networks (show_hidden == true)
  int nets = WiFi.scanNetworks(false, true);    
  

  // Prints a table with SSID name, RSSI, and encryption type for all networks found
  Serial.print("Wifi networks detected: ");
  Serial.println(nets);
  for (int i = 0; i < nets; ++i)                //++i is to check if number of nets is > 0, then set i to 1 to begin table print 
  {              
    //Print net details
    Serial.print(i + 1);
    Serial.print(":");
    Serial.print(WiFi.SSID(i));
    Serial.println(WiFi.RSSI(i));
    Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "   OPEN ":"   Password Required");
  }

  delay(SCAN_RATE);

}
