// Definir si el Arduino es el Transmisor (TX) o Receptor (RX)
// Cambia esto a false en el otro Arduino
#define IS_TRANSMITTER true 

#if IS_TRANSMITTER

// Código para el Arduino Transmisor (TX)
void setup() {
  // Configura la comunicación serial para transmitir
  Serial.begin(9600);
}

void loop() {
  // mensaje
  Serial.println("GRUPO 3 HA DOMADO");
  
  // 1 seg delay
  delay(1000);
}

#else

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// configuraciones pantalla 16x2
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  lcd.begin(16, 2);
  // Interacción con la pantalla
  lcd.print("Hola muchachos!");
}

void loop() {
  // ...
}

void setup() {
  
  // inicia la pantalla
  lcd.init();
  lcd.backlight();
  
  // mensaje en pantalla
  lcd.setCursor(0, 0);
  lcd.print("Esperando...");
}

void loop() {
  // Revisa si hay datos disponibles en el puerto serial
  if (Serial.available()) {
    // Lee la línea recibida por serial
    String receivedMessage = Serial.readStringUntil('\n');
    
    // Borra la pantalla LCD y muestra el mensaje recibido
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(receivedMessage);
  }
}

#endif
