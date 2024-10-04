 #informacion General
 La idea de este proyecto es crear un sistema que haga el riego automáticamente, sin las preocupaciones  por encender y apagar la bomba de agua. Usamos varios sensores que miden la humedad del suelo y si está lloviendo, todo conectado a un ESP32. Tambien vamos a mostrar los datos en una pantalla LCD para saber qué está pasando en tiempo real. La simulación la hacemos en Wokwi así puedes probar todo antes de montarlo en físico.

## Componentes 
Microcontrolador (ESP32): Lo elegimos porque es muy popular, fácil de programar y tiene un montón de pines para conectar sensores y controlar cosas como la bomba de agua. Tambien el ESP32 tiene Wi-Fi por si en el futuro queremos  controlarlo desde una app o ver el estado de nuestro dispocitivo.

**Sensores de humedad del suelo (resistivo y capacitivo):**

- Resistivo (YL-69, HL-69 o FC-28): Es el más común y barato. Funciona midiendo la resistencia en el suelo; si hay más agua, menos resistencia. Lo bueno es que es fácil de usar y barato. Lo malo es que con el tiempo se corroe por estar en contacto con el agua.
- Capacitivo (V1.2): Este es más profecional porque no se corroe, ya que no está en contacto directo con el agua. Además, da mediciones más estables. Lo usamos junto al resistivo para tener una medición más precisa.
- Sensor de lluvia (YL-83): Detecta si está lloviendo. Si el sensor detecta agua, el riego no se activa (porque si ya está lloviendo, no tiene sentido encender la bomba). Es simple pero muy útil para nuestraa plicacion.

**Pantalla LCD (16x2 o 20x4):**  Esta pantalla nos sirve para mostrar los datos importantes, como la humedad del suelo, si está lloviendo, o si la bomba está encendida. Es útil para ver qué está pasando sin tener que conectar una computadora al microcontrolador.

**Relé:** Este componente es el que se encarga de encender o apagar la bomba y la electroválvula. Lo bueno del relé es que puede controlar dispositivos de mayor potencia, como una bomba de agua, de manera segura.

**Bomba de agua:** La bomba es la encargada de mover el agua, Esto se activa automáticamente cuando los sensores detectan que hace falta regar. Lo bueno es que puedes hacer que el riego se ajuste solo, mejorando nuestro suelo para el cultivo.

**Sensor de nivel de tanque:** puede controlar que la bomba no se encienda si el tanque de agua está vacío. Nos ayuda a evitar que se dañe la bomba o que funcione innecesariamente.


## ¿Cómo funciona todo junto?
Primero, el sistema va a leer los valores de los sensores de humedad (resistivo y capacitivo). estos nos dicen si el suelo está seco o si ya tiene suficiente agua. Si el suelo está seco y no hay lluvia detectada (con el sensor YL-83), el Esp32 activa el relé para encender la bomba de agua y, El riego se detiene automáticamente si:

El suelo ya tiene suficiente humedad.
Empieza a llover.
El tanque de agua está vacío.
Todo esto se va a poder ver en la pantalla LCD, donde te mostrará los niveles de humedad y el estado del sistema-
