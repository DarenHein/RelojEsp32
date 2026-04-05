#include <WiFi.h>
#include "time.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <WiFi.h> 

#define screen_width 128
#define screen_height 64

Adafruit_SSD1306 display(screen_width, screen_height, &Wire, -1); 

const char* ssid     = "";
const char* password = "";

const long  gmtOffset_sec = -21600; 
const int   daylightOffset_sec = 0; 


void configurarReloj() {
  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWiFi conectado.");
  
  configTime(gmtOffset_sec, daylightOffset_sec, "pool.ntp.org", "time.google.com");
}

String obtenerHoraString() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    return "Error Hora";
  }
  char tiempoFormateado[12]; 
  strftime(tiempoFormateado, sizeof(tiempoFormateado), "%I:%M:%S", &timeinfo);
  
  return String(tiempoFormateado);
}

void iniciarPantalla(){
   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("No se encontró la pantalla OLED"));
    for(;;); 
  }
  display.clearDisplay();
  display.display();
}

void mostrarHoraEnPantalla(String hora){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE); 
  display.setCursor(15, 25);
  display.print(hora);
  display.display();
}

void limpiezaDePantalla(){
  display.clearDisplay(); 
}
void setup() {
  Serial.begin(115200);
  iniciarPantalla(); 
  configurarReloj();
}

void loop() {
  String horaActual = obtenerHoraString();
  mostrarHoraEnPantalla(horaActual); 
  delay(1000);  
}
