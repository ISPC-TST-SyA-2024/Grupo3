#include <DHT.h> 

#define PIN_DHT22 13 // Pin donde conectás el DHT22
#define DHTTYPE DHT22 // Tipo de sensor DHT
#define PRESION 34 // Pin para el potenciómetro que simula la presión
#define VIENTO 35 // Pin para el potenciómetro que simula el anemómetro
#define DIRECCION 32 // Pin para el potenciómetro que simula la veleta
#define LLUVIA 33 // Pin para el potenciómetro que simula el pluviómetro
#define HUMEDAD_SUELO 25 // Pin para el sensor de humedad de suelo

DHT dht(PIN_DHT22, DHTTYPE); // Creamos una instancia del sensor DHT

void setup() {
  Serial.begin(115200); // Iniciamos la comunicación serial a 115200 baudios
  dht.begin(); // Inicializamos el DHT
  // ¡Todo listo para empezar a leer datos del sensor!
}

void loop() {
  // Leemos temperatura y humedad del DHT22
  float temperatura = dht.readTemperature(); // Obtenemos la temperatura
  float humedad = dht.readHumidity(); // Obtenemos la humedad
  
  // Verificamos si hubo error en la lectura
  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("Error leyendo del sensor DHT");
    return; // Salimos de la función si hay un error
  }
  
  // Leemos los valores de los potenciómetros (simulan otros sensores)
  int presion = analogRead(PRESION); // Lectura del potenciómetro de presión
  int velocidadViento = analogRead(VIENTO); // Lectura del potenciómetro de velocidad de viento
  int direccionViento = analogRead(DIRECCION); // Lectura del potenciómetro de dirección de viento
  int precipitacion = analogRead(LLUVIA); // Lectura del potenciómetro de precipitación
  int humedadSuelo = analogRead(HUMEDAD_SUELO); // Simulación de humedad del suelo
  
  // Mostramos los datos en el monitor serial
  Serial.println("Estación Meteorológica");
  Serial.print("Temperatura: "); Serial.print(temperatura); Serial.println(" °C"); // Imprimimos la temperatura
  Serial.print("Humedad del Aire: "); Serial.print(humedad); Serial.println(" %"); // Imprimimos la humedad

  // Convertimos y mostramos los valores de los potenciómetros
  Serial.print("Presión Barométrica: "); Serial.print(map(presion, 0, 4095, 950, 1050)); Serial.println(" hPa");
  Serial.print("Velocidad del Viento: "); Serial.print(map(velocidadViento, 0, 4095, 0, 100)); Serial.println(" km/h");
  Serial.print("Dirección del Viento: "); Serial.print(map(direccionViento, 0, 4095, 0, 360)); Serial.println(" °");
  Serial.print("Precipitación: "); Serial.print(map(precipitacion, 0, 4095, 0, 100)); Serial.println(" mm");
  Serial.print("Humedad del Suelo: "); Serial.print(map(humedadSuelo, 0, 4095, 0, 100)); Serial.println(" %");
  
  Serial.println("----------------------------------");
  
  delay(2000); // Esperamos 2 segundos para la próxima lectura
}
