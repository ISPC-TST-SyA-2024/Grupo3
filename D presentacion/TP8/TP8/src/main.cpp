#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configuramos la pantalla LCD (dirección y tamaño 16x2)
LiquidCrystal_I2C pantalla(0x27, 16, 2);

// Pines de los potenciómetros (simuladores de sensores)
int lluvia = 34;             // Simula el sensor de lluvia
int sueloResistivo = 35;     // Simula el sensor resistivo de humedad del suelo
int sueloCapacitivo = 32;    // Simula el sensor capacitivo de humedad del suelo
int tanque = 33;             // Simula el nivel del tanque

// Salida del relé para controlar la bomba
int releBomba = 25;    

// Umbrales para activar el riego
int umbralLluvia = 2000;           // Valor para detectar lluvia
int umbralSueloResistivo = 1500;   // Valor para el suelo resistivo
int umbralSueloCapacitivo = 1500;  // Valor para el suelo capacitivo
int umbralTanqueBajo = 1000;       // Valor mínimo para tanque "bajo"
int umbralTanqueMedio = 2000;      // Valor mínimo para tanque "medio"
int umbralTanqueLleno = 3000;      // Valor para tanque "lleno"

void setup() {
  // Iniciar la pantalla LCD y el Monitor Serial
  pantalla.init();
  pantalla.backlight();
  
  pinMode(releBomba, OUTPUT);
  digitalWrite(releBomba, LOW);  // Apagamos la bomba al inicio
  
  Serial.begin(9600);

  // Mensaje inicial en la pantalla
  pantalla.setCursor(0, 0);
  pantalla.print("Sistema Riego");
  pantalla.setCursor(0, 1);
  pantalla.print("Iniciando...");
  delay(2000);  // Pausa para que se vea el mensaje
}

void loop() {
  // Leemos los valores de los potenciómetros (sensores simulados)
  int valorLluvia = analogRead(lluvia);
  int valorSueloResistivo = analogRead(sueloResistivo);
  int valorSueloCapacitivo = analogRead(sueloCapacitivo);
  int valorTanque = analogRead(tanque);

  // Mostrar en el Monitor Serial
  Serial.print("Lluvia: ");
  Serial.println(valorLluvia);
  Serial.print("Suelo Resistivo: ");
  Serial.println(valorSueloResistivo);
  Serial.print("Suelo Capacitivo: ");
  Serial.println(valorSueloCapacitivo);
  
  // Determinamos el nivel del tanque
  String nivelTanque;
  
  if (valorTanque >= umbralTanqueLleno) {
    nivelTanque = "Lleno";
  } else if (valorTanque >= umbralTanqueMedio) {
    nivelTanque = "Medio";
  } else {
    nivelTanque = "Bajo";
  }

  Serial.print("Nivel del Tanque: ");
  Serial.println(nivelTanque);

  // Mostrar los valores en la pantalla LCD
  pantalla.clear();
  pantalla.setCursor(0, 0);
  pantalla.print("Lluvia: ");
  pantalla.print(valorLluvia);
  
  pantalla.setCursor(0, 1);
  pantalla.print("SueloRes: ");
  pantalla.print(valorSueloResistivo);

  delay(2000);  // Pausa para ver el mensaje

  pantalla.clear();
  pantalla.setCursor(0, 0);
  pantalla.print("SueloCap: ");
  pantalla.print(valorSueloCapacitivo);
  
  pantalla.setCursor(0, 1);
  pantalla.print("Tanque: ");
  pantalla.print(nivelTanque);

  // Lógica para controlar el riego
  if (valorLluvia < umbralLluvia && 
      (valorSueloResistivo < umbralSueloResistivo || valorSueloCapacitivo < umbralSueloCapacitivo) &&
      nivelTanque != "Bajo") {
    
    // Si no llueve, el suelo está seco (cualquiera de los dos) y el tanque no está "bajo", activamos la bomba
    digitalWrite(releBomba, HIGH);  // Encendemos la bomba
    pantalla.setCursor(0, 1);
    pantalla.print("Riego: ON    ");
    Serial.println("Riego activado");
  } else {
    // Si llueve, el suelo está húmedo o el tanque está "bajo", apagamos la bomba
    digitalWrite(releBomba, LOW);   // Apagamos la bomba
    pantalla.setCursor(0, 1);
    pantalla.print("Riego: OFF    ");
    Serial.println("Riego desactivado");
  }

  Serial.println("----------------------------");

  delay(2000);  // Pausa antes de la siguiente lectura
}
