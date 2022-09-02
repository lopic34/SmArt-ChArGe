#include <Arduino.h>

// Personnal ID and credentials
#include "ids.h"

// WIFI
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>
//#include <ESP8266WebServer.h>

// information :
//  For WEMOS D1 R1, the LED_BUILTIN value is inverter:
//  HIGH to turn the LED OFF
//  LOW to turn the LED ON

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  // DNS check
  if (MDNS.begin("esp8266"))
  {
    Serial.println("MDNS responder started");
  }
}

void loop()
{
  // turn the LED OFF (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  // wait for ms
  delay(1000);
  // turn the LED ON by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  // wait for ms
  delay(100);
  // turn the LED OFF (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  // wait for ms
  delay(100);
  // turn the LED ON by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  // wait for a   // wait for ms
  delay(100);
}
