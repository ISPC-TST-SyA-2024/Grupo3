### ¿Cuáles son las ventajas y desventajas de una pantalla Nextion?

Las pantallas Nexion son un HMI (Human Machine Interface) inteligente que permiten la interaccion directa entre usuario y dispositivo mediate interfaz grafica. Y se comunican con los microcontroladores/PC/ sistema mediante un serial UART (formato ASCII o hexadecimal).

Estas tiene un microcontrolador embebido con memoria integrada o hasta con ranura microSD, vienen en variedad de tamañps y resolucione, son tactiles y vienen en variantes resistivas o capacitivas. De fabrica, viene con un sistema de  edicion, llamado editor Nexion. Es en resumidas cuentas un sistema drag n drop, lo que simplifica mucho trabajar con estas, permitiendo tambien programar en el mismo en lenguaje C. 

Dicho esto, podemos definir las ventajas y desventajas.

### Ventajas
- Desacoplamiento de la lógica de presentación y control, gracias a que maneja de forma autonoma, se puede evitar hacer todo esto con el microcontrolador.
- Simplicidad al momento de diseñar gracias a su sistema drag and drop.
- Menor consumo de recursos del microcontrolador. Como se encarga de algunas tareas libera al micro de realizarlas, y en tanto, optimiza el uso de recursos.
- Compatibilidad universal.
- Actualizacion y despligue sensillo.
- Interaccion tactil integrada. Mejora el ingreso de datos y es un nuevo estandar en dispositivos digitales el dia de hoy.
- Soporte gráfico avanzado (no en todas su versiones).

### Desventajas 
- Costo: Comparado con pantallas mas simples como las TFT, son mucho mas caras.
- Limitacione en la personalizacion. Como ya viene con un sistema de edicion incorporado, hay limites en cuanto se puede personalizar.
- Dependencia de software propietario. Nextion Editor es una plataforma propietaria. Por lo que el proyecto esta sujeto a actualizaciones, modificaciones, etc. De parte del prestador.
- Bajo rendimiento en proyectos grandes. Principalmente en sus versiones mas simples. Pueden tener problemas de rendimientos en proyectos grandes (multipantallas, graficos avanzados, animaciones complejas)
- Capacidad limitada para la programación lógica. Si bien permite programacion logica en C, pero con capacidad de scripting es limitada en comparacion con microcontroladores o sistemas embebidos mas complejos.
- Conexión limitada a UART. Puede resultar en un cuello de botella donde se requiere transferencia rapida de datos
- Interacción de un solo punto en pantallas resistivas. Lo que limita el ingreso/manipulacion de datos del usuario, si se compara con una multitactil.
- Consumo de energía: asi com son mas completas y avanzadas, aumente con esto su consumo de energia.

