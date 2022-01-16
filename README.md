# ESP8266 Serial Remote Syslog

Simple sketch to read the serial input of an ESP8266 and send it to a syslog server.

Handy for easily catching backtraces from another ESP device.

Uses this [Syslog library](https://github.com/arcao/Syslog).

## Usage / Setup

CLone this repo and modify the `main.cpp`:
```c
#define SSID ""
#define PASS ""

#define SYSLOG_SERVER ""
#define SYSLOG_PORT 514
```