/*#include <WiFi.h>
//#include <WiFiClientSecure.h>  //included WiFiClientSecure does not work!
#include "WiFiClientSecure.h" //using older WiFiClientSecure
#include <time.h>
#include <MQTT.h>
//#include "secrets.h"

#ifndef SECRET
  const char ssid[] = "JAZZTEL_vqFj";
  const char pass[] = "72ru2ut6kvrq";

  #define HOSTNAME "192.168.1.101"

  const char *MQTT_HOST = "192.168.1.101";
  const int MQTT_PORT = 8883;
  const char *MQTT_USER = "ciberfisicos1234"; // leave blank if no credentials used
  const char *MQTT_PASS = "ciberfisicos1234"; // leave blank if no credentials used

  const char* local_root_ca =
    "-----BEGIN CERTIFICATE\n" \
    "MIIDgzCCAmugAwIBAgIUHmrvdasrt3sbXZIIBAlQ6i0sZdQwDQYJKoZIhvcNAQEL\n" \
    "BQAwUTELMAkGA1UEBhMCRkkxEjAQBgNVBAcMCVNvbWUgQ2l0eTEWMBQGA1UEAwwN\n" \
    "MTkyLjE2OC4xLjEwMTEWMBQGA1UECwwNMTkyLjE2OC4xLjEwMTAeFw0yMTExMDIx\n" \
    "OTIzMTFaFw0yMjEyMDcxOTIzMTFaMFExCzAJBgNVBAYTAkZJMRIwEAYDVQQHDAlT\n" \
    "b21lIENpdHkxFjAUBgNVBAMMDTE5Mi4xNjguMS4xMDExFjAUBgNVBAsMDTE5Mi4x\n" \
    "NjguMS4xMDEwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDmvOdWTKx7\n" \
    "mkk+8hth/oBqgHDZUSUsCw7BCTGiLljgsPoYrm4Y/3Dok+yTMsBFKVhkcr7PIZCV\n" \
    "LDw8w+95I+8BT9t3lr6Jdf5s41xFiCS+1N2BzOfaWx9E6nA4nXrSyzg8O/V6ygsh\n" \
    "18a9XsZID1UGBBiBnFvL2ftVuuTAwjbGH3hHfCoxwhjl8kEj0Ug2Z4mbJuwERLlr\n" \
    "a9G+8FOsws+LFfcBnT8ruFR/PSy0wWEz0xTx7hkXsiwXImjOWVHAoeMSI7DFLjt9\n" \
    "X0KSVh+vAVxuWfP8jwWmKV7dAR5YbLuWr4ZkPu/xqfk+amVDJUbajz2v6eb2+fIP\n" \
    "lwIDR9je17KfAgMBAAGjUzBRMB0GA1UdDgQWBBTwgWemmHSJ3xogsFF65MkKRkMg\n" \
    "IzAfBgNVHSMEGDAWgBTwgWemmHSJ3xogsFF65MkKRkMgIzAPBgNVHRMBAf8EBTAD\n" \
    "AQH/MA0GCSqGSIb3DQEBCwUAA4IBAQDHv7j8+vDZsmvDgSkDRfie3o0x32N5UiqA\n" \
    "tZwieUxN8TffNXKN5fizVaDisR6A0RjDlrR2gbK8bjQ0lot1G1OtVX1PtkRcBbFl\n" \
    "1XYgH6iWQ3ist3tbt1MLGwOoElIUIYbEL2PHJ1xNFPRW3dsM4DFCjd2JZJl0po0J\n" \
    "IM1oTnvGSOKhr8Ah5enxme4+tJEpRqqbuvVDzRt2PL1MGHKRwVgLg3Ts5luCplmq\n" \
    "Mt1Y2pmvXoRStyKbOqPaUHe408SH/VmOlmTYSXY/l1jHIsqPOzE2HshjJIYI3p8d\n" \
    "Y4LohKC97J5qeUyJzotfHyq37xkSc2lEa1BV0m6+3TL4yibkEnBg\n" \
    "-----END CERTIFICATE-----\n";

#endif

const char MQTT_SUB_TOPIC[] = "temperatures";
const char MQTT_PUB_TOPIC[] = "temperatures";

WiFiClientSecure net;
MQTTClient client;

time_t now;
unsigned long lastMillis = 0;

void mqtt_connect()
{
  Serial.print("Time: ");
  Serial.print(ctime(&now));
  Serial.print("MQTT connecting");
  while (!client.connect(HOSTNAME, MQTT_USER, MQTT_PASS))
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("connected!");
  client.subscribe(MQTT_SUB_TOPIC);
}

void messageReceived(String &topic, String &payload)
{
  Serial.println("Received [" + topic + "]: " + payload);
}

void setup()
{
  Serial.begin(115200);

  Serial.print("Attempting to connect to SSID: ");
  Serial.println(ssid);
  WiFi.setHostname(HOSTNAME);
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(ssid);

  /*Serial.print("Setting time using SNTP ");
  configTime(-5 * 3600, 0, "pool.ntp.org", "time.nist.gov");
  now = time(nullptr);
  while (now < 1510592825) {
    delay(500);
    Serial.print(".");
    now = time(nullptr);
  }
  Serial.println("");
  struct tm timeinfo;
  gmtime_r(&now, &timeinfo);*/
  /*Serial.print("Current time: ");
  Serial.print(ctime(&now));

  net.setCACert(local_root_ca);
  client.begin(MQTT_HOST, MQTT_PORT, net);
  client.onMessage(messageReceived);
  mqtt_connect();
}

void loop()
{
  //now = time(nullptr);
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Checking wifi");
    while (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(10);
    }
    Serial.println("connected");
  }
  else
  {
    if (!client.connected())
    {
      mqtt_connect();
    }
    else
    {
      client.loop();
    }
  }

  if (millis() - lastMillis > 5000) {
    lastMillis = millis();
    client.publish(MQTT_PUB_TOPIC, ctime(&now), false, 0);
  }
}*/

#include <WiFi.h>
//#include <WiFiClientSecure.h>  //included WiFiClientSecure does not work!
#include "WiFiClientSecure.h" //using older WiFiClientSecure
#include <time.h>
#include <PubSubClient.h>
//#include "secrets.h"

#ifndef SECRET
  const char ssid[] = "JAZZTEL_vqFj";
  const char pass[] = "72ru2ut6kvrq";

  #define HOSTNAME "192.168.1.101"

  const char *MQTT_HOST = "192.168.1.101";
  const int MQTT_PORT = 8883;
  const char *MQTT_USER = "ciberfisicos1234"; // leave blank if no credentials used
  const char *MQTT_PASS = "ciberfisicos1234"; // leave blank if no credentials used

  const char* local_root_ca = \
    "-----BEGIN CERTIFICATE\n" \
    "MIIDgzCCAmugAwIBAgIUHmrvdasrt3sbXZIIBAlQ6i0sZdQwDQYJKoZIhvcNAQEL\n" \
    "BQAwUTELMAkGA1UEBhMCRkkxEjAQBgNVBAcMCVNvbWUgQ2l0eTEWMBQGA1UEAwwN\n" \
    "MTkyLjE2OC4xLjEwMTEWMBQGA1UECwwNMTkyLjE2OC4xLjEwMTAeFw0yMTExMDIx\n" \
    "OTIzMTFaFw0yMjEyMDcxOTIzMTFaMFExCzAJBgNVBAYTAkZJMRIwEAYDVQQHDAlT\n" \
    "b21lIENpdHkxFjAUBgNVBAMMDTE5Mi4xNjguMS4xMDExFjAUBgNVBAsMDTE5Mi4x\n" \
    "NjguMS4xMDEwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDmvOdWTKx7\n" \
    "mkk+8hth/oBqgHDZUSUsCw7BCTGiLljgsPoYrm4Y/3Dok+yTMsBFKVhkcr7PIZCV\n" \
    "LDw8w+95I+8BT9t3lr6Jdf5s41xFiCS+1N2BzOfaWx9E6nA4nXrSyzg8O/V6ygsh\n" \
    "18a9XsZID1UGBBiBnFvL2ftVuuTAwjbGH3hHfCoxwhjl8kEj0Ug2Z4mbJuwERLlr\n" \
    "a9G+8FOsws+LFfcBnT8ruFR/PSy0wWEz0xTx7hkXsiwXImjOWVHAoeMSI7DFLjt9\n" \
    "X0KSVh+vAVxuWfP8jwWmKV7dAR5YbLuWr4ZkPu/xqfk+amVDJUbajz2v6eb2+fIP\n" \
    "lwIDR9je17KfAgMBAAGjUzBRMB0GA1UdDgQWBBTwgWemmHSJ3xogsFF65MkKRkMg\n" \
    "IzAfBgNVHSMEGDAWgBTwgWemmHSJ3xogsFF65MkKRkMgIzAPBgNVHRMBAf8EBTAD\n" \
    "AQH/MA0GCSqGSIb3DQEBCwUAA4IBAQDHv7j8+vDZsmvDgSkDRfie3o0x32N5UiqA\n" \
    "tZwieUxN8TffNXKN5fizVaDisR6A0RjDlrR2gbK8bjQ0lot1G1OtVX1PtkRcBbFl\n" \
    "1XYgH6iWQ3ist3tbt1MLGwOoElIUIYbEL2PHJ1xNFPRW3dsM4DFCjd2JZJl0po0J\n" \
    "IM1oTnvGSOKhr8Ah5enxme4+tJEpRqqbuvVDzRt2PL1MGHKRwVgLg3Ts5luCplmq\n" \
    "Mt1Y2pmvXoRStyKbOqPaUHe408SH/VmOlmTYSXY/l1jHIsqPOzE2HshjJIYI3p8d\n" \
    "Y4LohKC97J5qeUyJzotfHyq37xkSc2lEa1BV0m6+3TL4yibkEnBg\n" \
    "-----END CERTIFICATE-----\n";
;

#endif

const char MQTT_SUB_TOPIC[] = "temperatures";
const char MQTT_PUB_TOPIC[] = "temperatures";

WiFiClientSecure net;
PubSubClient client(net);

time_t now;
unsigned long lastMillis = 0;

void mqtt_connect()
{
    while (!client.connected()) {
    Serial.print("Time:");
    Serial.print(ctime(&now));
    Serial.print("MQTT connecting");
    if (client.connect(HOSTNAME, MQTT_USER, MQTT_PASS)) {
      Serial.println("connected");
      client.subscribe(MQTT_SUB_TOPIC);
    } else {
      Serial.print("failed, status code =");
      Serial.print(client.state());
      Serial.println("try again in 5 seconds");
      /* Wait 5 seconds before retrying */
      delay(5000);
    }
  }
  
}

void receivedCallback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Received [");
  Serial.print(topic);
  Serial.print("]: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
}

void setup()
{
  Serial.begin(115200);

  Serial.print("Attempting to connect to SSID: ");
  Serial.println(ssid);
  WiFi.setHostname(HOSTNAME);
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(ssid);

  /*Serial.print("Setting time using SNTP");
  configTime(-5 * 3600, 0, "pool.ntp.org", "time.nist.gov");
  now = time(nullptr);
  while (now < 1510592825) {
    delay(500);
    Serial.print(".");
    now = time(nullptr);
  }
  Serial.println("");
  struct tm timeinfo;
  gmtime_r(&now, &timeinfo);
  Serial.print("Current time: ");
  Serial.print(asctime(&timeinfo));*/

  net.setCACert(local_root_ca);
  client.setServer(MQTT_HOST, MQTT_PORT);
  client.setCallback(receivedCallback);
  mqtt_connect();
}

void loop()
{
  now = time(nullptr);
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Checking wifi");
    while (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(10);
    }
    Serial.println("connected");
  }
  else
  {
    if (!client.connected())
    {
      mqtt_connect();
    }
    else
    {
      client.loop();
    }
  }

  if (millis() - lastMillis > 5000) {
    lastMillis = millis();
    client.publish(MQTT_PUB_TOPIC, ctime(&now), false);
  }
}
