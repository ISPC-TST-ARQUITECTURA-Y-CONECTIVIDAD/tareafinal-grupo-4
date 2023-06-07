# PRIMER ENSAYO DE CÓDIGO GPSV1.0
#include <TinyGPS++.h>
#include <HardwareSerial.h>
#include <WiFi.h>
#include <Wire.h>               
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> 
#include <BlynkSimpleEsp32.h>

float latitud , longitud;
String  latitud_string , longitiud_string;

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64  

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const char *ssid =  "SSID";     
const char *pass =  "Password"; 
char auth[] = "ec8EX0fnX1y78Oo6pO8lp8Of_AWUd***"; 

WidgetMap myMap(V0); 
WiFiClient client;
TinyGPSPlus gps;
HardwareSerial SerialGPS(2);


void setup()
{
  Serial.begin(115200);
if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");             
  }
  Serial.println("");
  Serial.println("WiFi connected!");

  SerialGPS.begin(9600, SERIAL_8N1, 16, 17);
  Blynk.begin(auth, ssid, pass);
  Blynk.virtualWrite(V0, "clr"); 
}
void loop()
{
  while (SerialGPS.available() > 0) {
    if (gps.encode(SerialGPS.read()))
    {
      if (gps.location.isValid())
      {
        latitud = gps.location.lat();
        latitud_string = String(latitud , 6);
        longitud = gps.location.lng();
        longitiud_string = String(longitud , 6);
        Serial.print("Latitud = ");
        Serial.println(latitud_string);
        Serial.print("Longitud = ");
        Serial.println(longitiud_string);
        
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 20);
  display.println("Latitud: ");
  display.setCursor(45, 20);
  display.print(latitud_string);
  display.setCursor(0, 40);
  display.print("Longitud: ");
  display.setCursor(45, 40);
  display.print(longitiud_string);
 
        Blynk.virtualWrite(V0, 1, latitud, longitud, "Location");
        display.display();
      }
     delay(1000);
     Serial.println();  
    }
  }  
  Blynk.run();
}
