// Pines
const int pinTX = 1;  // GPIO1

void setup() {
  // Inicialización del puerto serial y el pin TX
  Serial.begin(9600);
  pinMode(pinTX, OUTPUT);
}

void loop() {
  // Enviar un mensaje
  String mensaje = "Hola desde el transmisor";
  Serial.println("Enviando: " + mensaje);

  // Convertir el mensaje a caracteres y enviarlo
  for (int i = 0; i < mensaje.length(); i++) {
    digitalWrite(pinTX, HIGH); // Simulando envío
    delay(100);  // Simulando el tiempo de transmisión
    digitalWrite(pinTX, LOW);
    delay(100);
  }

  delay(2000);  // Esperar antes de enviar el siguiente mensaje
}