#include <HCSR04.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

// Initialize sensor that uses digital pins 13 and 12.
const byte triggerPin = 13;
const byte echoPin = 12;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup()
{ 
  //Define as portas dos leds como saida
  pinMode(11, OUTPUT); // VERDE
  pinMode(10, OUTPUT); // VERMELHO
  //Distancia LIMITE
  float distance_lim = 50;

  Serial.begin(115200);                     // Conexão serial
  WiFi.begin("yourSSID", "yourPASS");       // Troque pelo SSID e senha da sua rede Wi-Fi 
  
  while (WiFi.status() != WL_CONNECTED) {   // Aguarda conectar à rede Wi-Fi
    delay(500);
    Serial.println("Waiting for connection"); 
  } 
}
  
void loop()
{
  //Coleta distancia pelo módulo
  float distance = distanceSensor.measureDistanceCm();
  
  // Verifica se distancia é maior ou menos que a distancia_lim
  if (distance < distance_lim) {
    digitalWrite(10, HIGH); //Acende o led vermelho se distancia menor que distancia limite
  } else { 
    digitalWrite(11, HIGH);
    } //Acende o led verde se distancia maior que distancia limite
  
  elay(200);
}