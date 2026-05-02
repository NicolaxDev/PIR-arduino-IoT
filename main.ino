#include <WiFi.h>
#include <HTTPClient.h>
#include <UrlEncode.h>

#define WIFI_SSID ""
#define WIFI_PASS ""

String apiKey = "";
String mobileNumber = "";

WiFiClient Client;

// PIR
#define PIR_PIN 13

bool movimientoDetectado = false;
unsigned long tiempoUltimoMensaje = 0;
const int intervalo = 10000;

void setup() {

  Serial.begin(9600);

  pinMode(PIR_PIN, INPUT);

  WiFi.mode(WIFI_STA);
  
  Serial.print("Connecting...");
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("...");
    delay(500);
  }

  Serial.println();
  Serial.println("Connected!");
}

void loop() {

  int estadoPIR = digitalRead(PIR_PIN);

  if (estadoPIR == HIGH) {
    
    Serial.println("Movimiento detectado!");

    // Message delay
    if (!movimientoDetectado || (millis() - tiempoUltimoMensaje > intervalo)) {
      
      sendWhatsapp("ALERTA!! MOVIMIENTO DETECTADO");
      
      movimientoDetectado = true;
      tiempoUltimoMensaje = millis();
    }

  } else {
    movimientoDetectado = false;
  }

  delay(500);
}

void sendWhatsapp(String message) {
  
  String url = "https://api.callmebot.com/whatsapp.php?phone=" + mobileNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message); 
  HTTPClient http;
  http.begin(url);

  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int responseCode = http.POST(url);
  if (responseCode == 200) {
    Serial.println("Mensaje enviado correctamente!");
  } else {
    Serial.print("Error enviando el mensaje: ");
    Serial.println(responseCode);
  }
      
  http.end();
}