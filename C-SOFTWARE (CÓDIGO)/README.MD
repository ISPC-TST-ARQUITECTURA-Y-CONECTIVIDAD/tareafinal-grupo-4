# PRIMER ENSAYO DE CÓDIGO GPSV1.0
## ¿Cómo funciona el código?
En esta sección, veamos cómo funciona el código.

## Incluyendo Bibliotecas
En primer lugar, incluiremos todas las siguientes bibliotecas que se requieren para este proyecto. El WiFi.h y se utilizará para conectarse a la red inalámbrica. El Wire.h nos permitirá comunicarnos a través del protocolo I2C. Mientras que las otras bibliotecas son las que instalamos previamente y son necesarias para el correcto funcionamiento de la pantalla OLED, el módulo GPS y la aplicación Blynk.

![Sin título](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/ee48ddc6-886d-4aa4-9fa8-bf7620386752)

## Definición de pantalla OLED
Primero definiremos el ancho y alto de nuestra pantalla OLED en píxeles. Estamos usando una pantalla de 128 × 64, por lo que el ancho será 128 y la altura será 64.

![Sin título1](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/b4b9db61-f86f-40d4-9942-eed82af13fa1)

A continuación, inicializaremos la pantalla creando un objeto de Adafruit_SSD1306 y especificando el ancho, la altura, la instancia I2C (&Wire) y -1 como parámetros dentro de él.' -1 'especifica que la pantalla OLED que estamos usando no tiene un pin RESET. Si está utilizando el pin RESET, especifique el GPIO a través del cual lo está conectando con su placa de desarrollo.

![Sin título](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/dbd1f031-e360-47cc-814f-88b49cd829a1)

## Definición de variables
A continuación, definiremos algunas variables de cadena y flotante que usaremos más adelante en el código. Estos guardarán los valores de latitud y longitud.

![Sin título](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/ee4fe0af-7721-45a7-9274-c78135036921)

## Configuración de credenciales de red
Ahora, necesitamos definir el nombre SSID y la contraseña. Las siguientes líneas establecen el nombre del SSID y la contraseña. Puede reemplazar el SSID y la contraseña por sus propias credenciales de red.

![Sin título](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/b2e0cf20-e0f8-4f3e-94ee-e0307869d7b2)

## Definición de clave de autorización
Definiremos la clave de autorización que se nos envió por correo electrónico a través de Blynk en nuestra cuenta a través de la cual iniciamos sesión. Mantenga esta clave segura con usted por motivos de seguridad.

![Sin título](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/534cea51-f5e7-4143-84dc-9a91a0a49470)

## Creación de instancias
Cree las siguientes instancias para el mapa de widgets, el cliente wifi, la biblioteca TinyGPSPlus y HardwareSerial.

![Sin título](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/44f3a946-b0f9-4c80-8095-31359c60bec4)

## configuración()
Dentro de la función setup(), abriremos una conexión serial a una tasa de baudios de 115200.

![Sin título](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/3bd2664f-6522-485d-a312-609b1788f1eb)

Además, también inicializaremos la pantalla OLED usando display.begin(). Asegúrese de especificar la dirección correcta de su pantalla. En nuestro caso, es 0X3C.

![Sin título](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/a26f4510-d815-4da6-873e-f5898ca5971a)

La siguiente sección de código conectará nuestra placa ESP32 con la red local cuyas credenciales de red ya especificamos anteriormente. Usaremos la función WiFi.begin(). Los argumentos serán el SSID y la contraseña que definimos anteriormente en el código. Después de establecer una conexión exitosa, "¡Conectado a la red WiFi!" se mostrará en el monitor serie.

![Sin título](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/60efe4f9-ece0-4a3b-af06-808735409d37)

Ahora, el módulo GPS y la aplicación Blynk también están inicializados.

![Sin título](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/3300eede-d799-4c76-bfb8-854791a81717)

## bucle()
Dentro de la función loop(), obtendremos datos del módulo GPS y comprobaremos si los parámetros de ubicación son válidos o no. Si los parámetros son válidos, guardamos los valores de longitud y latitud en sus respectivas variables después de convertirlos en un formato legible.

![Sin título](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/12d13c1a-a84d-444d-9ba1-555e13ee68ff)

Estos valores entrarán en el monitor serie.

![Sin título](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/275d016d-f33d-4cd7-819d-9f21b60ef50e)

Además, también mostraremos la ubicación en la pantalla OLED. Esto se hace mediante las siguientes líneas de código.
Primero, limpiaremos el búfer usando clearDisplay() en el objeto Adafruit_SSD1306. A continuación, controlaremos el color del texto usando la función setTextColor() y pasando BLANCO como argumento. Estableceremos el tamaño del texto usando setTextSize() y pasaremos el tamaño como un parámetro dentro de él. Hemos establecido el tamaño de fuente como predeterminado, que es 1. Usaremos la función setCursor() para indicar la posición del eje xey desde donde debe comenzar el texto. Luego, usando print(), pasaremos el texto que queremos mostrar en el OLED. Colocaremos el cursor nuevamente en diferentes posiciones para mostrar todos los valores correctamente. Llamaremos a la función display() en el objeto de visualización para que el texto se muestre en el OLED.

![Sin título](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/17be51e5-6042-4833-9ec5-b097e6cf273d)

Estos datos GPS también se envían a la aplicación Blynk. El mapa mostrará la posición actual del vehículo/persona accediendo a los valores de latitud y longitud.

![Sin título](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/b4a78e8b-36c4-4f18-8338-6d326c0e6839)

Dentro de la función de bucle, usaremos el comando Blynk.run() para mantener la conexión en funcionamiento.

![Sin título](https://github.com/ISPC-TST-ARQUITECTURA-Y-CONECTIVIDAD/tareafinal-grupo-4/assets/106171748/530f2e79-7c47-4cbf-b566-56735ca80a40)

## Programa completo
Archivo ESP32GPS1


