#include <Arduino.h>
#line 1 "C:\\Users\\Vitto Dell\\RX\\RX.ino"
#include <SoftwareSerial.h>

// Definimos los pines para la recepción (SoftwareSerial)
const int pinRX = 12;  // Pin D3 como RX
SoftwareSerial mySerial(-1, pinRX);  // Solo recepción

#line 7 "C:\\Users\\Vitto Dell\\RX\\RX.ino"
void setup();
#line 13 "C:\\Users\\Vitto Dell\\RX\\RX.ino"
void loop();
#line 7 "C:\\Users\\Vitto Dell\\RX\\RX.ino"
void setup() {
  mySerial.begin(9600);  // Inicia SoftwareSerial a 9600 baudios
  Serial.begin(9600);  // Para depuración en monitor serial
  Serial.println("Receptor listo");
}

void loop() {
  if (mySerial.available()) {  // Si hay datos recibidos
    String mensajeRecibido = mySerial.readStringUntil('\n');  // Leer mensaje
    Serial.println("Mensaje recibido: " + mensajeRecibido);  // Mostrar en serial
  }
  delay(1000);  // Esperar un poco antes de la siguiente lectura
}

