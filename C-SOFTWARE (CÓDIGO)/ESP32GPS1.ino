#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

SoftwareSerial gpsSerial(4, 5); // RX, TX
TinyGPSPlus gps;

char ssid[] = "Fibertel WiFi118 2.4GHz"; // Reemplaza con el nombre de tu red WiFi
char password[] = "01425268647"; // Reemplaza con la contraseña de tu red WiFi
char blynk_auth_token[] = "qF4dgxrhwNsM9HmlQaaa6j67BVKXpcbi"; // Reemplaza con tu token de autenticación de Blynk
char blynk_template_id[] = "TMPL2fixnzWWw"; // Reemplaza con el ID del template en Blynk
char blynk_template_name[] = "ESP32GPS"; // Reemplaza con el nombre del template en Blynk

BlynkTimer timer;

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  
  // Inicializar la pantalla OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("No se pudo inicializar la pantalla OLED");
    while (true);
  }
  
  // Inicializar la conexión WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado");
  
  // Inicializar Blynk
  Blynk.begin(blynk_auth_token, ssid, password);
  
  // Configurar la función de actualización de datos cada segundo
  timer.setInterval(1000L, enviarDatosBlynk);
  
  // Limpiar la pantalla OLED
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("GPS+OLED+Blynk");
  display.display();
  delay(2000);
}

void loop() {
  // Ejecutar las funciones de Blynk y TinyGPS++
  Blynk.run();
  actualizarGPS();
  timer.run();
}

void enviarDatosBlynk() {
  if (gps.location.isValid()) {
    // Obtener latitud y longitud
    float latitude = gps.location.lat();
    float longitude = gps.location.lng();
    
    if (gps.altitude.isValid()) {
      // Obtener altitud en metros
      float altitude = gps.altitude.meters();
      Blynk.virtualWrite(V1, altitude);
    }
    
    if (gps.speed.isValid()) {
      // Obtener velocidad en kilómetros por hora
      float speedKmph = gps.speed.kmph();
      Blynk.virtualWrite(V2, speedKmph);
    }
    
    // Enviar latitud y longitud a Blynk
    Blynk.virtualWrite(V3, latitude);
    Blynk.virtualWrite(V4, longitude);
  }
  
  if (gps.satellites.isValid()) {
    // Obtener número de satélites
    int satellites = gps.satellites.value();
    
    // Enviar número de satélites a Blynk
    Blynk.virtualWrite(V5, satellites);
  }
}

void actualizarGPS() {
  while (gpsSerial.available()) {
    if (gps.encode(gpsSerial.read())) {
      if (gps.location.isValid()) {
        // Obtener latitud y longitud
        float latitude = gps.location.lat();
        float longitude = gps.location.lng();
        
        // Mostrar los datos en la pantalla OLED
        display.clearDisplay();
        display.setCursor(0, 0);
        display.print("Latitud: ");
        display.println(latitude, 6);
        display.print("Longitud: ");
        display.println(longitude, 6);
        
        if (gps.altitude.isValid()) {
          // Obtener altitud en metros
          float altitude = gps.altitude.meters();
          display.print("Altitud: ");
          display.print(altitude, 2);
          display.println(" m");
        }
        
        if (gps.speed.isValid()) {
          // Obtener velocidad en kilómetros por hora
          float speedKmph = gps.speed.kmph();
          display.print("Velocidad: ");
          display.print(speedKmph, 2);
          display.println(" km/h");
        }
        
        display.display();
      }
    }
  }
}
