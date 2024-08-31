# Cálculo de errores en la lectura de un sensor de temperatura
---
Un sensor de temperatura con un rango de medida de 20-250 °C entrega una lectura de 55 °C. El objetivo es especificar el error en la lectura del sensor si la exactitud se expresa de las siguientes formas:

**a)** ± 0,5% del valor máximo de lectura

**b)** ± 0,75% del alcance (FS)

**c)** ± 0,8% de la lectura.

### Datos:
---
Rango de medida del sensor: 20 °C a 250 °C

Valor de la lectura: 55 °C

Rango completo del sensor (FS): 250 - 20 = 230 °C

### Explicación de los cálculos:
---
Para calcular el error en la lectura del sensor de temperatura, es necesario aplicar el porcentaje de exactitud a la referencia correspondiente. Dependiendo de cómo se exprese la exactitud, se utilizan diferentes fórmulas: 

**1. Porcentaje del valor máximo de lectura:** Se calcula el error tomando el porcentaje del valor máximo que el sensor puede leer. Esto significa que el error está basado en el valor máximo del rango del sensor (250 °C en este caso). La fórmula es: Error = (Porcentaje de exactitud / 100) × Valor máximo de lectura.

**2. Porcentaje del alcance (FS):** El alcance o 'Full Scale' (FS) es el rango completo de medición del sensor, que se obtiene restando el valor mínimo del valor máximo del sensor. En este caso, FS = 250 °C - 20 °C = 230 °C. El error se calcula aplicando el porcentaje de exactitud al FS. La fórmula es: Error = (Porcentaje de exactitud / 100) × FS.

**3. Porcentaje de la lectura actual:** En este caso, el error depende directamente del valor leído por el sensor (55 °C en este ejemplo). La exactitud se expresa como un porcentaje de la lectura actual. La fórmula es: Error = (Porcentaje de exactitud / 100) × Valor de la lectura.

### Cálculo del error
---
#### a) ± 0,5% del valor máximo de lectura
El error se calcula como un porcentaje del valor máximo de lectura del sensor.

Error = ± 0.5% × 250 °C = ± 1.25 °C

#### b) ± 0,75% del alcance (FS)
El error se calcula como un porcentaje del rango completo del sensor (Full Scale o FS).

Error = ± 0.75% × 230 °C = ± 1.725 °C

#### c) ± 0,8% de la lectura
El error se calcula como un porcentaje de la lectura actual del sensor.

Error = ± 0.8% × 55 °C = ± 0.44 °C

### Resumen de los Errores:
---
**a)** ±1.25 °C

**b)** ±1.725 °C

**c)** ±0.44 °C