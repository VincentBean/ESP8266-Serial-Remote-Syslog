#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Syslog.h>

#define LED 5

#define SSID ""
#define PASS ""

#define SYSLOG_SERVER ""
#define SYSLOG_PORT 514

#define DEVICE_HOSTNAME "esp8266"
#define APP_NAME "serial"

#define UART_BAUD 115200

WiFiUDP udpClient;
Syslog syslog(udpClient, SYSLOG_SERVER, SYSLOG_PORT, DEVICE_HOSTNAME, APP_NAME, LOG_KERN);

void setup()
{
  pinMode(LED, OUTPUT);

  WiFi.mode(WIFI_STA);

  WiFi.begin(SSID, PASS);

  while (WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(400);
  }

  Serial.begin(UART_BAUD);

  syslog.log(LOG_INFO, "Started remote uart to syslog!");
}

void loop()
{

  if (!Serial.available())
  {
    return;
  }

  syslog.log(LOG_INFO, Serial.readString());
}