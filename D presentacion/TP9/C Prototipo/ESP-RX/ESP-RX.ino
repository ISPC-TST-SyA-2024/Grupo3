// Pines
const int pinRX = 0;  // GPIO0

void setup() {
  // Inicialización del puerto serial y el pin RX
  Serial.begin(9600);
  pinMode(pinRX, INPUT);
}

void loop() {
  String mensajeRecibido = "";

  // Leer datos simulados del pin RX
  while (digitalRead(pinRX) == HIGH) {
    mensajeRecibido += "1";  // Simulando lectura de bits
    delay(100);
  }

  if (mensajeRecibido.length() > 0) {
    Serial.println("Mensaje recibido: " + mensajeRecibido);
  }

  delay(2000);  // Esperar antes de la próxima lectura
}
