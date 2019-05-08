#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
 
const char* ssid = "Chidq";
const char* password = "chidananda";
int numRotations =4 ;
int batteryPercentage= 99;
 int ledPin = 13;
WiFiServer server(80);

SoftwareSerial ESP2(D2,D3);
 
void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  ESP2.begin(4800);
  pinMode(D1, INPUT);
  pinMode(D2, OUTPUT);
 
}
 
void loop() {
    receiveData();
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  if (request.indexOf("/rot") != -1) {

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println(numRotations);
        client.println(batteryPercentage);
  }
  else if (request.indexOf("/bat") != -1) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println(batteryPercentage);
  }
}
void receiveData(){
   while(ESP2.available()>0)
    {
    float val = ESP2.parseFloat();
          if(ESP2.read() == '\n'){
            numRotations = val;
            batteryPercentage--;
             Serial.println(val);
             Serial.println(batteryPercentage);   
          }
    }
  }
