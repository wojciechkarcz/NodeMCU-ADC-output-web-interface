/*
 *Program przeznaczony do odczytywania wartosci analogowych rejestrowanych przez NodeMCU 
 *za pomoca prostego interfejsu WWW
 *Program stworzony przez Centrum Nauki Kopernik w ramach projektu Ersamus+ Hands on Remote 
 */
 
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h" //odniesienie do pliku index.h, w ktorym znajduje sie kod HTML ze strona www oraz skrypty JS
#define LED 2  

//Nazwa i haslo sieci wifi tworzonej przez NodeMCU; mozna je dowolnie zmienic 
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


//==============================================================
//                  SETUP
//==============================================================
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

//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  server.handleClient();         
}
