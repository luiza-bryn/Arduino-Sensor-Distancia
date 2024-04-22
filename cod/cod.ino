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

void send_http_get() {
  if (WiFi.status() == WL_CONNECTED) {                   // Verifica estado do Wi-Fi 
     WiFiClient client;                                  // Declara variável WiFIClient
     HTTPClient http;                                    // Declara variável HTTPClient    
     http.begin(client, "http://localhost:5000/api/distancia_limite");  // Define URL
     http.addHeader("Content-Type", "text/plain");       // Especifica tipo de conteúdo
     int httpCode = http.GET();                          // Envia requisição HTTP GET 
     String payload = http.getString();                  // Obtém os dados de resposta
     Serial.println(httpCode);                           // Imprime código de retorno
     Serial.println(payload);                            // Imprime dados de resposta
     http.end();                                         // Fecha a conexão
  } else { 
    Serial.println("Error in WiFi connection"); 
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