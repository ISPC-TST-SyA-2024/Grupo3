<img src="./E assets/caratula.png">

# Sensores y Actuadores

## Modulo 1: Estructura de Redes IoT 

----------------------

### Profesor
- Ing. Morales Jorge Elias | https://github.com/JorEl057

### Miembros:
- Durigutti, Vittorio | GitHub: https://github.com/vittoriodurigutti
- Zalazar, Joaquín | GitHub: https://github.com/breaakerr
- Marquez, José | Github: https://github.com/marquezjose
- Lujan, Luciano | Github: https://github.com/lucianoilujan
- Velez, Nahuel | Github: https://github.com/Lucasmurua19
- Juncos, Lisandro | Github: https://github.com/Lisandro-05
- Garzón, Joaquín | Github: https://github.com/Joacogarzonn


 ## link de proyecto https://wokwi.com/projects/409918402625391617
# Información general de la estación
 En este informe te cuento cómo funciona nuestra estación meteorológica, que utiliza un sensor DHT22 para medir la temperatura y la humedad del aire. Además, simula otros sensores mediante potenciómetros, lo que me permite obtener información sobre las condiciones meteorológicas como presión, velocidad del viento, dirección del viento, y precipitaciones.

Funcionamiento: El código que he implementado tiene dos partes principales. Primero, configura el sensor DHT22 para que pueda leer la temperatura y la humedad. Cada dos segundos, el programa lee estos valores y los imprime en el monitor serial.

### cómo funciona:

Inicialización: Cuando enciendo la estación, se inicializan todos los componentes: el sensor DHT, los potenciómetros, y la comunicación serial.
Lectura de datos: En el bucle principal **(loop())**, se lee la temperatura y la humedad del DHT22. También se obtienen los valores de los potenciómetros que simulan otros sensores.
### Las variables que se simulan son:
- Presión Barométrica: Simulada con un potenciómetro conectado al pin 34.
- Velocidad del Viento: Simulada con un potenciómetro conectado al pin 35.
- Dirección del Viento: Simulada con un potenciómetro conectado al pin 32.
- Precipitación: Simulada con un potenciómetro conectado al pin 33.
- Humedad del Suelo: Simulada con un potenciómetro conectado al pin 25.
### Salida de datos: 
se muestran todos los datos en el monitor serial para que pueda ver cómo están las condiciones meteorológicas en tiempo real.
Además, si el sensor DHT22 tiene problemas para leer, el código se encarga de mostrar un mensaje de error en el monitor.

### Aplicaciones: 
Esta estación meteorológica tiene múltiples aplicaciones, que van desde usos educativos hasta prácticas en el hogar. 

- Monitoreo del clima local: Ideal para saber cómo están las condiciones en el lugar donde se encuentra la estación.
- Aprendizaje sobre meteorología: Perfecta para estudiantes o entusiastas de la ciencia que quieran aprender sobre cómo funcionan los sensores y la recolección de datos meteorológicos.
- Proyectos de IoT: Puede integrarse en proyectos más grandes, donde se necesite recopilar datos ambientales y enviarlos a una base de datos o una interfaz gráfica.
- Control ambiental: Junto con otros componentes, podría usarse para controlar sistemas de calefacción o ventilación en función de la temperatura y la humedad.
