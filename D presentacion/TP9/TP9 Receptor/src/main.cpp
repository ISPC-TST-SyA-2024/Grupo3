#include <Arduino.h>
#include <SPI.h>       // Librería para la comunicación SPI
#include <RH_ASK.h>    // Librería RadioHead para manejar la recepción ASK

RH_ASK rf_driver;  // driver del módulo RF 

void setup() {
  // Iniciamos el driver del módulo RF. Si algo falla, lo indicamos por Serial.
  if (!rf_driver.init()) {
    Serial.println("No se pudo iniciar el módulo RF :(");
  }

  // Iniciar la comunicación Serial para ver lo que pasa en el monitor serial
  Serial.begin(9600);
}

void loop() {
  // Creamos un buffer donde vamos a guardar el mensaje recibido
  uint8_t buf[12];  // Asumimos que el mensaje es de 12 caracteres como máximo 
  uint8_t buflen = sizeof(buf);  // Esto nos dice cuánto espacio hay en el buffer

  // Revisamos si hemos recibido algo. Si sí, lo procesamos.
  if (rf_driver.recv(buf, &buflen)) {
    // Convertimos el mensaje del buffer a texto y lo mostramos en el monitor serial
    Serial.print("Mensaje recibido: ");
    Serial.println((char*)buf);  // Mostramos lo que recibimos cambianmos texto con (char*)
  }
}
