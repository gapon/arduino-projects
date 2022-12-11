#include <SPI.h>
#include <SD.h>
#include "DHT.h"

#define DHTPIN 2   
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
File f1;

int pinCS = 10;

void setup()
{
  Serial.begin(9600);

  Serial.print("Initializing SD card...");
  if (!SD.begin(pinCS))
  {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  if (SD.exists("test.txt"))
  {
    SD.remove("test.txt");
    Serial.println("File removed.");
  }

  dht.begin();
  delay(2000);
}

void loop() {
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  f1 = SD.open("test.txt", FILE_WRITE);
  if (f1)
  {
    Serial.print("Writing to test.txt...");

    f1.print(h);
    f1.print("\t");
    f1.println(t);

    f1.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  
  delay(600000);

}