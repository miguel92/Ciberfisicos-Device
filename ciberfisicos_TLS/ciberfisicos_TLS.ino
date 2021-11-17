#include <WiFi.h>
#include <time.h>
#include <PubSubClient.h>
#include "secrets.h"
#include <HTTPClient.h>

const char MQTT_SUB_TOPIC[] = "distancias";
const char MQTT_PUB_TOPIC[] = "distancias";
char cadena[64];
int distancia = 0;
String tokenString = "";
WiFiClientSecure net;
WiFiClientSecure net2;
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

int random_distance(){
    int distancia = random(0,30);
    return distancia;
}

String request_token(){
    String response = "";
    String request = "{\"email\": \"esp32@correo.com\", \"password\": \"esp32pass\"}";
    net2.print(request.c_str());
    while (net2.connected() || net2.available()) {
        if (net2.available()) {
            response = net2.readStringUntil('\n');
            net2.stop();
        }
    }
    return response;
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

    Serial.println();
    Serial.print("Connected to ");
    Serial.println(ssid);

    net.setCACert(local_root_ca);
    net2.setCACert(jwt_root_ca);

    if(!net2.connect(jwt_IP,60000)){
      char err_buf[100];

      if(net2.lastError(err_buf,100)<0){
        Serial.println("Last WifiSecureClient Error: ");
        Serial.println(err_buf);
      }
        
    }else{
        Serial.println("Conectado al server JWT");
        tokenString = request_token();
    }

    client.setServer(MQTT_HOST, MQTT_PORT);
    client.setCallback(receivedCallback);
    mqtt_connect();
}

void loop()
{
    now = time(nullptr);
    if (WiFi.status() != WL_CONNECTED){
        Serial.print("Checking wifi");
        while (WiFi.waitForConnectResult() != WL_CONNECTED){
            WiFi.begin(ssid, pass);
            Serial.print(".");
            delay(10);
        }
        Serial.println("connected");
    }else{
        if (!client.connected()){
          mqtt_connect();
        }else{
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
