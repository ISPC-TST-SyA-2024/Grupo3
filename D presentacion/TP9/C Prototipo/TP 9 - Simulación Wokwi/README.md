# Explicación del Montaje con Dos Arduinos y una Pantalla LCD 16x2 con I2C

En este esquema, he conectado dos **Arduino UNO** entre sí, y también a una pantalla **LCD 16x2** con interfaz **I2C**. 
A continuación, explico las conexiones de manera detallada:

## 1. Comunicación Serie entre Arduinos
He establecido una comunicación en serie entre los dos Arduinos utilizando sus pines **TX** y **RX**:
- **TX (Transmisión) del Arduino UNO 1** está conectado al **RX (Recepción) del Arduino UNO 2**. Esto permite que el primer Arduino
 envíe datos al segundo.

- **RX del Arduino UNO 1** está conectado al **TX del Arduino UNO 2**. Esto asegura la comunicación bidireccional, permitiendo que 
ambos Arduinos puedan intercambiar datos.

La finalidad de esta conexión es que los Arduinos se comuniquen entre sí utilizando la interfaz UART (*Universal Asynchronous Receiver-Transmitter*), donde uno puede actuar como transmisor y el otro como receptor. Esto es fundamental en aplicaciones donde se necesita que los Arduinos compartan información o coordinen acciones.

## 2. Conexión del LCD 16x2 con I2C
La pantalla **LCD 16x2** está conectada al **Arduino UNO 1** mediante la interfaz **I2C**, utilizando solo 4 cables:

- **VCC** de la pantalla está conectado a **5V** del Arduino UNO 1, y **GND** de la pantalla está conectado a **GND** 
del mismo Arduino, para suministrar la alimentación necesaria a la pantalla.

- **SDA (Serial Data)** de la pantalla LCD está conectado al pin **A4** del Arduino UNO 1, que es el pin designado 
para la transmisión de datos en el protocolo I2C.

- **SCL (Serial Clock)** de la pantalla está conectado al pin **A5** del mismo Arduino, que se encarga de sincronizar 
los datos a través del reloj.

Este tipo de conexión con **I2C** es más eficiente, ya que solo requiere dos pines para controlar la pantalla, en comparación 
con otros métodos que requieren más cables para el control. A través de I2C, se pueden enviar 
comandos y datos desde el Arduino hacia la pantalla LCD, permitiendo mostrar información como datos procesados o mensajes.

## Justificación del Diseño
Este montaje permite lograr dos cosas:
1. **Comunicación en serie entre Arduinos**: Es útil para crear proyectos en los que múltiples microcontroladores necesitan colaborar o intercambiar datos, por ejemplo, para distribuir tareas entre ellos.
2. **Visualización en la pantalla LCD**: El primer Arduino envía o recibe datos y los visualiza en la pantalla LCD utilizando la interfaz I2C, lo que lo hace eficiente en cuanto al uso de pines.

El sistema es modular, ya que se pueden añadir más dispositivos I2C si se requiere, y los Arduinos pueden recibir y enviar información simultáneamente a otros periféricos.

---

Este es el diseño del sistema y su explicación. Si se requiere, se puede extender la funcionalidad del mismo añadiendo más dispositivos o sensores.
