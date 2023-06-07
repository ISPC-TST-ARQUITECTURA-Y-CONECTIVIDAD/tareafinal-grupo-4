# Componentes necesarios para el Sistema GPS
En esta sección, veremos una breve introducción de los componentes necesarios para el sistema de rastreo GPS ESP32:

## Módulo GPS NEO 6M (Es una opción)
Usaremos el módulo GPS NEO 6M para ayudarnos a diseñar el localizador a través de GPS. Consiste en un motor de posicionamiento u-blox 6 de alto rendimiento. Con unas medidas de 16 x 12,2 x 2,4 mm, su arquitectura compacta junto con su bajo consumo de energía lo convierten en una buena opción para proyectos de IoT. En general, es un buen receptor GPS rentable. La siguiente tabla muestra algunas características clave del módulo.
![Sin título](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/ba8f1fce-b99d-416c-aefa-71bedd67376a)
## Asignación de pines del módulo NEO 6M
El siguiente diagrama muestra la salida de pines del módulo NEO 6M. Consta de 4 pines denominados GND, TX, RX y VCC.
![NEO-6M-GPS-module-pin-out](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/2935242e-0577-4a8b-95c8-12c51e971fbb)
![Sin título1](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/42b13316-23e2-4715-8caf-7b14e0c9e7f8)

## Pantalla OLED SSD1306 de 0,96 pulgadas
Aunque hay varios tipos de pantallas OLED disponibles en el mercado, la que usaremos es la pantalla OLED SSD1306 de 0,96 pulgadas. El componente principal de todos los diferentes tipos de pantallas OLED es un controlador SSD1306 que utiliza el protocolo I2C o SPI para comunicarse con los microcontroladores. El OLED funciona más rápido en la comunicación SPI pero es popular con la comunicación I2C. La razón de la popularidad es el menor número de pines. Las pantallas OLED pueden variar en tamaño, color y forma, pero se programan principalmente de manera similar.

La pantalla OLED que usaremos se llama SSD 1306 Pantalla OLED de 0,96 pulgadas que tiene 128 × 64 píxeles y se comunica solo a través del protocolo I2C con las placas de desarrollo ESP. Es barato y fácilmente disponible en el mercado.

## Asignación de pines de la pantalla OLED (solo I2C)
A continuación puede ver el pinout de esta pantalla OLED.
![OLED-pinout-diagram-768x768](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/7ab695f6-1a10-4099-8bfb-51617f89d01f)

