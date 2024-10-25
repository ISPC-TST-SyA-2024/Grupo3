## TP 9  

Realizamos la simulacion en Proteus, mediante el uso de dos librerias con las cuales pudimos integrar el microcontrolador ESP32, y modulos TX y RX. Se incorpora luego, la libreria correspondiente a Arduino Nano.
Las mismas se encuentren en D presentacion\TP9\Librerias en formato .zip/.rar

**Links de las librerias:**
 - RF TX y RX: https://www.theelectronics.co.in/2020/11/arduino-rf-module-simulation-proteus.html
 - ESP32: https://goalmdcat.com/esp32-library-for-proteus/
 - ARDUINO NANO: https://microchipotle.com/descargar-librerias-de-arduino-para-proteus/

 # investigación

 **La radiofrecuencia (RF)**  se refiere al rango de frecuencias dentro del espectro electromagnético, que va aproximadamente de los 3 kHz a los 300 GHz, utilizadas para transmitir información de forma inalámbrica. para la  generación de RF implica el uso de un oscilador que generan ondas de radio de una  frecuencia específica, esta misma luego transmitidas por una antena. Estas ondas transportan informacion en modulaciones como **ASK (amplitud), FSK (frecuencia) y PSK (fase)**.

### Principales Características de la Radiofrecuencia:
-Rango de Frecuencia: El rango de radiofrecuencia incluye desde frecuencias de audio (kHz) hasta microondas (GHz).

### Modulación de RF:

-ASK (Amplitud): Se usa en modulos de bajo costo y corto alcance, como los de 433 MHz.
-FSK (Frecuencia): mas estable y resistente a interferencias, se usa en módulos como el HC-12.
-PSK (Fase): mas complejo y usado en comunicaciones de alta velocidad, como en WiFi.
-Transceptores RF: Estos módulos de RF combinan un transmisor y receptor, usando pines dedicados de transmisión (TX) y recepción (RX). -Ejemplos incluyen NRF24L01 y HC-12, que permiten comunicación bidireccional en varias aplicaciones.

## Módulo RF 433 MHz
**Descripción:** este modulo simple y economico se utiliza en la banda de 433 MHz  los modulos de RF a 433 MHz, estan compuestos por un transmisor y un receptor que envían señales digitales simples en largas distancias  generalmente entre 100 y 200 metros en exteriores
- Utilizan modulación ASK (amplitud) para transmitir datos de un Arduino a otro o entre sensores.

#### Ventajas:

Económico y fácil de implementar.
Compatible con largas distancias en condiciones adecuadas.

#### Desventajas:

- son sensible a interferencias de otros dispositivos en la misma banda.
- velocidad de datos baja, adecuada solo para información simple.

#### Caracteristicas

- Rango: hasta 200 metros en exteriores  
- Velocidad de datos: aproximadamente 4 kbps  
- Voltaje de operación: 3.3V a 5V  

## Módulo NRF24L01
**Descripción:** este módulo transceptor opera en la banda de 2.4 GHz permitiendo comunicación en tiempo real con velocidades de hasta 2 Mbps y configuraciones en malla.  

#### Ventajas:

- alta velocidad de transmision.
- red multicanal con capacidad para varios dispositivos en simultaneo.
- bajo consumo energetico.

#### Desventajas:

-la señal puede ser afectada por obstáculos.
- Requiere un convertidor de nivel de voltaje si se conecta a dispositivos de 5V.


#### Caracteristicas

- Frecuencia: 2.4 GHz
- Rango: Hasta 100 metros en exteriores
- Velocidad de datos: Hasta 2 Mbps
- Interfaz: Comunicación SPI

