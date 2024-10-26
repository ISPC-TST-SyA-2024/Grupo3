#include <SoftwareSerial.h>

// Definimos los pines para la transmisión (SoftwareSerial)
const int pinTX = 12;  // Pin D2 como TX
SoftwareSerial mySerial(pinTX, -1);  // Solo transmisión

void setup() {
  mySerial.begin(9600);  // Inicia SoftwareSerial a 9600 baudios
  Serial.begin(9600);  // Para depuración en monitor serial
}

void loop() {
  String mensaje = "Hola desde el transmisor";
  
  // Enviar mensaje por el puerto serial
  mySerial.println(mensaje);
  Serial.println("Enviando: " + mensaje);  // Ver en monitor serial
  
  delay(2000);  // Esperar 2 segundos antes del siguiente envío
}

