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


 ## link de proyecto https://wokwi.com/projects/410829584635409409 
 
# Información general del proyecto
 En este informe te voy a contar cómo funciona nuestro Sistema de Riego Inteligente que utiliza diferentes sensores simulados para monitorear las condiciones de humedad del suelo y del clima, activando o desactivando una bomba de agua según sea necesario. Los sensores de humedad del suelo (tanto resistivo como capacitivo) y el sensor de lluvia se simulan mediante potenciómetros, y el nivel del tanque de agua también se simula con otro potenciómetro.

Funcionamiento: Cuando enciendo el sistema, se inicializan todos los componentes: los potenciómetros que simulan los sensores de humedad del suelo, lluvia y nivel del tanque, así como la pantalla LCD y la salida del relé que controla la bomba.
### cómo funciona:

Inicialización:
Cuando enciendo el sistema, se inicializan todos los componentes: los potenciómetros que simulan los sensores de humedad del suelo, lluvia y nivel del tanque, así como la pantalla LCD y la salida del relé que controla la bomba.

En el bucle principal **(loop())**, se leen los valores de los potenciómetros que simulan los sensores:

- Sensor de lluvia: Simulado con un potenciómetro conectado al pin 34.
- Sensor de humedad del suelo resistivo: Simulado con un potenciómetro conectado al pin 35.
- Sensor de humedad del suelo capacitivo: Simulado con un potenciómetro conectado al pin 32.
- Nivel del tanque: Simulado con un potenciómetro conectado al pin 33, que nos da tres niveles: "Lleno", "Medio" y "Bajo".

### Las variables que se simulan son:
- Lluvia: Simulada con un potenciómetro conectado al pin 34.
- Humedad del suelo (resistivo): Simulada con un potenciómetro conectado al pin 35.
- Humedad del suelo (capacitivo): Simulada con un potenciómetro conectado al pin 32.
- Nivel del tanque: Simulado con un potenciómetro conectado al pin 33, mostrando los valores "Lleno", "Medio", y "Bajo".

### Lógica de riego:
El sistema activa la bomba si:

- No está lloviendo (sensor de lluvia).
- La humedad del suelo, medida por cualquiera de los sensores (resistivo o capacitivo), está por debajo de un cierto umbral.
- El tanque de agua no está en nivel "bajo", es decir, que tenga suficiente agua para activar el riego.
- **Si cualquiera de estas condiciones no se cumple, la bomba se apaga automáticamente.**

### Salida de datos: 
se muestran todos los datos en el monitor serial para que pueda ver cómo están las condiciones del suelo.
todos los datos se muestran tanto en el Monitor Serial como en una pantalla LCD de 16x2 con interfaz I2C, lo que me permite monitorear el estado de los sensores en tiempo real y saber si la bomba está activada o desactivada.

### Aplicaciones: 
Esta estación meteorológica tiene múltiples aplicaciones, que van desde usos educativos hasta prácticas en el hogar. 

- Monitoreo del riego: Ideal para usar en jardines o huertos donde se necesite un riego eficiente y basado en las condiciones del clima.
- Proyectos educativos: Perfecto para estudiantes que quieran aprender cómo integrar sensores en proyectos de IoT, simulando diferentes condiciones ambientales.
- Automatización del riego: Este sistema puede formar parte de una red más grande de IoT, que recopile datos del ambiente y los procese para hacer el riego completamente automático.
- Optimización de recursos: Ayuda a controlar y reducir el uso de agua, activando el riego solo cuando es necesario, y evitando desperdicios si está lloviendo o si el suelo ya tiene suficiente humedad.