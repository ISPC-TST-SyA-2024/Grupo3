#include <VirtualWire.h> // Biblioteca para comunicación RF
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>

// Definición de pines
#define DATA_PIN 12 // Pin de datos

// Crear objeto para la pantalla LCD
LiquidCrystal_I2C lcd(0x3F, 16, 2); // Asegúrate de que la dirección sea correcta

void setup() {
  Serial.begin(9600); // Iniciar la comunicación serial
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Esperando mensaje");

  vw_set_rx_pin(DATA_PIN); // Configurar el pin de datos
  vw_setup(2000); // Configurar la velocidad en baudios (2000 bps)
  
  vw_rx_start(); // Comenzar a recibir mensajes
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN]; // Buffer para almacenar el mensaje recibido
  uint8_t buflen = VW_MAX_MESSAGE_LEN; // Tamaño del buffer

  if (vw_get_message(buf, &buflen)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Mensaje recibido:");
    lcd.setCursor(0, 1);
    lcd.print((char*)buf); // Mostrar el mensaje en la segunda línea
    delay(2000); // Esperar antes de limpiar la pantalla
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Esperando mensaje");
  }
}
