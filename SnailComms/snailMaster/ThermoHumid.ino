//#include "DHT.h"
//
//#define DHTPIN 5     // Digital pin connected to the DHT sensor
//// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
//// Pin 15 can work but DHT must be disconnected during program upload.
//
//// Uncomment whatever type you're using!
////#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
////#define DHTTYPE DHT21   // DHT 21 (AM2301)
//
//// Initialize DHT sensor.
//// Note that older versions of this library took an optional third parameter to
//// tweak the timings for faster processors.  This parameter is no longer needed
//// as the current DHT reading algorithm adjusts itself to work on faster procs.
//
//
//
//DHT dht(DHTPIN, DHTTYPE);
//
//
//
//void SetupThermoHumid() {
//
//  Serial.println("Setting up ThermoHumidity Sensor");
//  dht.begin();
//}
//
//float GetTemp() {
//  
//  // Wait a few seconds between measurements.
//  delay(2000);
//
//  // Reading temperature or humidity takes about 250 milliseconds!
//  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
//  // Read temperature as Celsius (the default)
//  float t = dht.readTemperature();
//
//  // Check if any reads failed and exit early (to try again).
//  if (isnan(t)) {
//    Serial.println(F("Failed to read from thermometer sensor!"));
//    return 0;
//  }
//
//  return t;
//}
//
//float GetHumid() {
//
//  // Wait a few seconds between measurements.
//  delay(2000);
//   
//  // Read humidity
//  float h = dht.readHumidity();
//
//  // Check if any reads failed and exit early (to try again).
//  if (isnan(h)) {
//    Serial.println(F("Failed to read from humidity sensor!"));
//    return 0;
//  }
//
//  return h;
//  
//}
