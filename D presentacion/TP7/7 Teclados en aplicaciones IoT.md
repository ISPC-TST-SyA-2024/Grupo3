## ¿Cómo se comunican?

En aplicaciones de IoT, los teclados pueden funcionar utilizando protocolos de comunicación como UART, SPI o I2C, dependiendo de los requisitos del sistema
y las características del teclado.

### 1. **UART (Universal Asynchronous Receiver-Transmitter):**
   - **Funcionamiento en teclados**: Aunque UART es más común para la comunicación serial entre dispositivos (como un microcontrolador y un módulo Bluetooth),
	también se puede utilizar para la interacción con teclados. Un teclado con UART transmite los datos pulsados en forma de bytes seriales de manera
	asíncrona (sin una señal de reloj). Cada tecla presionada se traduce en un código de tecla específico (generalmente en formato ASCII), que se envía
	al microcontrolador a través de los pines de transmisión (TX) y recepción (RX).
	
   - **Ventajas en IoT**: 
     - Simplicidad de implementación.
     - Usualmente requiere solo dos líneas (TX y RX).
	 
   - **Desventajas**:
     - La velocidad de transmisión puede no ser ideal para aplicaciones que requieren gran cantidad de datos en tiempo real.
     - No es eficiente en sistemas donde hay muchos dispositivos conectados.


### 2. **SPI (Serial Peripheral Interface):**
   - **Funcionamiento en teclados**: SPI es un protocolo más rápido que UART y es sincrónico, lo que significa que utiliza una señal de reloj para sincronizar
	la comunicación entre dispositivos. Los teclados que usan SPI generalmente transmiten los datos pulsados como bytes en serie. Un microcontrolador
	maestro controla el reloj (SCK), y cada tecla presionada se envía a través de las líneas *MOSI* o *MISO*, dependiendo de la configuración del dispositivo.
	
   - **Ventajas en IoT**:
     - Alta velocidad de transmisión.
     - Soporte para múltiples dispositivos (varios teclados u otros periféricos) mediante la selección de esclavos.
   
   - **Desventajas**:
     - Requiere más líneas (SCK, MOSI, MISO, y una línea de selección por dispositivo esclavo).
     - Puede ser más complejo de implementar que UART.


### 3. **I2C (Inter-Integrated Circuit):**
   - **Funcionamiento en teclados**: I2C es un protocolo sincrónico que utiliza dos líneas (SCL y SDA) para la comunicación entre el microcontrolador (maestro)
	y dispositivos esclavos, como un teclado. Los teclados con I2C envían datos de las teclas pulsadas a través de la línea de datos (SDA), sincronizados
	por una señal de reloj (SCL). Cada dispositivo esclavo tiene una dirección única, por lo que es posible conectar varios dispositivos (incluso teclados)
	en el mismo bus.
   
   - **Ventajas en IoT**:
     - Solo requiere dos líneas de comunicación, lo que facilita la integración en sistemas con muchos dispositivos.
     - La dirección de esclavos permite tener múltiples teclados o periféricos en el mismo bus.
   
   - **Desventajas**:
     - La velocidad de transmisión es menor en comparación con SPI.
     - Pueden surgir problemas con la longitud del bus o el ruido en sistemas más complejos.


## Aplicación en IoT:
En una red IoT, un teclado podría utilizarse para ingresar comandos o datos que serán transmitidos a otros dispositivos o servicios a través de la nube o
una red local. Dependiendo de la configuración, el teclado puede enviar datos a un microcontrolador (como el ESP32) y, luego, este puede retransmitir la
información mediante WiFi, Bluetooth, o incluso mediante protocolos como MQTT.

Por ejemplo, en un sistema de control de acceso, un teclado podría estar conectado a un dispositivo que verifica los datos ingresados (como un código PIN)
y luego envía esta información a un servidor en la nube para su validación. Dependiendo del entorno y los requisitos, cualquier de estos tres
protocolos (UART, SPI o I2C) podría ser adecuado, aunque I2C suele ser el más utilizado para periféricos pequeños en sistemas IoT, dado su balance entre
simplicidad y eficiencia.