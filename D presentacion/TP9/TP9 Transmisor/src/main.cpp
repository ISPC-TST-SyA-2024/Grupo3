#include <Arduino.h>
#include <SPI.h>       // Librería para la comunicación SPI (para el módulo RF)
#include <RH_ASK.h>    // Librería RadioHead para manejar la transmisión ASK (Amplitude Shift Keying)

// Crear el driver del módulo RF 

void setup() {
  // Iniciar el driver del módulo RF. Si algo falla, lo indicamos por Serial.
  if (!rf_driver.init()) {
    Serial.println("Algo salió mal al iniciar el módulo RF!");
  }

  // Iniciar la comunicación Serial para ver lo que pasa en el monitor serial
  Serial.begin(9600);
}

void loop() {
  // Definimos el mensaje que vamos a enviar
  const char *mensaje = "Hello World";  

  // Ahora, mandamos el mensaje usando el módulo RF
  rf_driver.send((uint8_t *)mensaje, strlen(mensaje));

  // Esperamos a que el mensaje termine de enviarse antes de hacer otra cosa
  rf_driver.waitPacketSent();

  // Mostramos en el monitor serial que el mensaje fue enviado
  Serial.println("Mensaje enviado: Hello World");

  // Esperamos 1 segundo antes de enviar el mensaje otra vez
  delay(1000);
}
