#include <WiFi.h>
#include <time.h>
#include <PubSubClient.h>
#include "secrets.h"
#include <HTTPClient.h>

const char MQTT_SUB_TOPIC[] = "temperatures";
const char MQTT_PUB_TOPIC[] = "temperatures";
char cadena[64];
int distancia = 0;
String tokenString = "";
WiFiClientSecure net;
PubSubClient client(net);

time_t now;
unsigned long lastMillis = 0;

void mqtt_connect()
{
    while (!client.connected()) {
    Serial.print("Time:");
    Serial.print(ctime(&now));
    Serial.print("MQTT connecting ");
    if (client.connect(HOSTNAME, MQTT_USER, tokenString.c_str())) {
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
  Serial.println("");
}

void setup()
{
  Serial.begin(115200);

  Serial.print("Attempting to connect to SSID: ");
  Serial.println(ssid);
  WiFi.setHostname(HOSTNAME);
  WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS);
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }

  
  tokenString = request_token();
  tokenString = tokenString.substring(1,tokenString.length()-1);
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(ssid);

  //Bloque para obtener la hora de un servidor
  /*
  Serial.print("Setting time using SNTP");
  configTime(+1 * 3600, 0, "pool.ntp.org", "time.nist.gov");
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
  Serial.print(asctime(&timeinfo));
  */
  net.setCACert(local_root_ca);
  //net.setCertificate(ESP_CA_cert);
  //net.setPrivateKey(ESP_RSA_key);
  client.setServer(MQTT_HOST, MQTT_PORT);
  client.setCallback(receivedCallback);
  mqtt_connect();
}
int random_distance(){
  int distancia = random(0,15);
  return distancia;
  }

String request_token(){
   HTTPClient http;   
   String response = "";
   http.begin("http://192.168.1.101:3000/login");  //Specify destination for HTTP request
   http.addHeader("Content-Type", "application/json");             //Specify content-type header
  
   int httpResponseCode = http.POST("{\"email\": \"esp32@correo.com\", \"password\": \"esp32pass\"}");   //Send the actual POST request
  
   if(httpResponseCode>0){
  
    response = http.getString();                       //Get the response to the request
    Serial.println(httpResponseCode);   //Print return code
    Serial.println(response);           //Print request answer
  
   }else{
  
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);
  
   }
  
   http.end();  //Free resources

   return response;
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
    distancia = random_distance();
    snprintf(cadena,64,"%d",distancia);
    client.publish(MQTT_PUB_TOPIC, cadena, false);
  }
}
