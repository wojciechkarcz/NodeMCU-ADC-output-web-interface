#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h" //name of the template file with HTML and JS scripts; must be in the same directory
#define LED 2  

//SSID and password of wifi network created by NodeMCU. If password left blank, there will be an open network created.
const char* ssid = "NodeMCU";
const char* password = "";

ESP8266WebServer server(80); 

void handleRoot() {
 server.send(200, "text/html", MAIN_page); //Send web page
}

void handleADC() {
 int a = analogRead(A0);
 String adcValue = String(a);
 digitalWrite(LED,!digitalRead(LED)); 
 server.send(200, "text/plane", adcValue); 
}


//==================================================
//                  SETUP
//==================================================
void setup(void){
  Serial.begin(115200);
  WiFi.softAP(ssid, password);

  Serial.println(" ");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());    
 
  server.on("/", handleRoot);      
  server.on("/readADC", handleADC); 

  server.begin();                  
  Serial.println("HTTP server started");
  pinMode(LED,OUTPUT);
}

//===================================================
//                     LOOP
//===================================================
void loop(void){
  server.handleClient();         
}
