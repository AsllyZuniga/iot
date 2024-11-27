#include "DHT.h"

// Configuración del DHT11
#define DHTPIN 15  // Pin conectado al DATA del DHT11
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);  // Ajusta a 9600 baudios para ser consistente con Python
  Serial.println(F("Iniciando DHT..."));
  dht.begin();
}

void loop() {
  // Leer temperatura y humedad
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  // Validar lectura
  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println(F("Error al leer del DHT!"));
    return;
  }

  // Enviar datos en el formato esperado
  Serial.print("Temp: ");
  Serial.print(temperatura);
  Serial.print(", Hum: ");
  Serial.println(humedad);

  delay(10000);  // Esperar 2 segundos antes de la siguiente lectura
}

