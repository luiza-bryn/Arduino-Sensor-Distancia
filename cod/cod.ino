#include <HCSR04.h>

// Initialize sensor that uses digital pins 13 and 12.
const byte triggerPin = 13;
const byte echoPin = 12;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);
float distance_lim = 10;

void setup()
{ 
  //Define as portas dos leds como saida
  pinMode(11, OUTPUT); // VERDE
  pinMode(10, OUTPUT); // VERMELHO
  //Distancia LIMITE
}

void loop()
{
  //Coleta distancia pelo módulo
  float distance = distanceSensor.measureDistanceCm();
  
  // Verifica se distancia é maior ou menos que a distancia_lim
  if (distance < distance_lim) {
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH); //Acende o led vermelho se distancia menor que distancia limite
  } else { 
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    } //Acende o led verde se distancia maior que distancia limite
  
  delay(200);
}