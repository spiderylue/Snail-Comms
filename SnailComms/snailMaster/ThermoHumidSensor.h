#include "DHT.h"

class ThermoHumidSensor {

  uint8_t DHTTYPE = DHT22;
  DHT dht;

public:

  ThermoHumidSensor(uint8_t DHTPin) : dht { DHTPin, DHTTYPE }  {
    Serial.println("Setting up ThermoHumidity Sensor");
    dht.begin();
  }
  
  float GetTemp() {
    
    // Wait a few seconds between measurements.
    delay(2000);
  
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();
  
    // Check if any reads failed and exit early (to try again).
    if (isnan(t)) {
      Serial.println(F("Failed to read from thermometer sensor!"));
      return 0;
    }
    return t;
  }
  
  float GetHumid() {
  
    // Wait a few seconds between measurements.
    delay(2000);
     
    // Read humidity
    float h = dht.readHumidity();
  
    // Check if any reads failed and exit early (to try again).
    if (isnan(h)) {
      Serial.println(F("Failed to read from humidity sensor!"));
      return 0;
    }
  
    return h; 
  }
};
