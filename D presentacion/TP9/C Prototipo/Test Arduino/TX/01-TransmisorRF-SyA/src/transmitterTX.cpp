#include <VirtualWire.h> // Biblioteca para comunicación RF
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // Biblioteca para controlar el LCD I2C
#include <SPI.h>

#define DATA_PIN 12 // Pin de datos

// Crear objeto para la pantalla LCD con dirección 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2); // Cambia a 16x2 si es necesario

void setup() {
  // Inicializar la biblioteca VirtualWire
  vw_set_tx_pin(DATA_PIN); // Configurar el pin de datos
  vw_setup(2000); // Configurar la velocidad en baudios (2000 bps)

  Serial.begin(9600); // Iniciar la comunicación serial

  // Inicializar el LCD
  lcd.begin(16, 2); // Inicializar el LCD con 16 columnas y 2 filas
  lcd.backlight(); // Encender la luz de fondo del LCD
  lcd.setCursor(0, 0); // Colocar el cursor en la primera línea
  lcd.print("Listo para enviar"); // Mensaje inicial en el LCD
}

void loop() {
  const char *mensaje = "Hola Mundo"; // Mensaje a enviar

  // Enviar el mensaje
  vw_send((uint8_t *)mensaje, strlen(mensaje));
  vw_wait_tx(); // Esperar a que se complete la transmisión

  Serial.println("Mensaje enviado: Hola Mundo");
  
  lcd.clear(); // Limpiar el LCD
  lcd.setCursor(0, 1); // Colocar el cursor en la segunda línea
  lcd.print("Mensaje enviado"); // Mostrar mensaje en el LCD
  
  delay(2000); // Esperar antes de enviar de nuevo
}