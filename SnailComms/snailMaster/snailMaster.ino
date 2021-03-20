#include "ThermoHumidSensor.h"


int HYGROMETER_FRONT_POWERPIN = 2;
int HYGROMETER_FRONT_SENSORPIN = A2;
int HYGROMETER_BACK_POWERPIN = 3;
int HYGROMETER_BACK_SENSORPIN = A3;

ThermoHumidSensor ThermoHumidFront(5);

void setup() {
  Serial.begin(9600);
  Serial.println("SnailComms is booting");
  
  SetupDisplay();
  //SetupThermoHumid();
  SetupHygrometer(HYGROMETER_FRONT_POWERPIN);
  SetupHygrometer(HYGROMETER_BACK_POWERPIN);

}

void loop() {

  float Temp = ThermoHumidFront.GetTemp();
  float HygroFront = GetHygro(HYGROMETER_FRONT_SENSORPIN, HYGROMETER_FRONT_POWERPIN);
  float HygroBack = GetHygro(HYGROMETER_BACK_SENSORPIN, HYGROMETER_BACK_POWERPIN);
  float Hum = ThermoHumidFront.GetHumid();

  ClearDisplay();
  UpdateDisplay(0, HygroFront, Temp, Hum);
  UpdateDisplay(1, HygroBack, Temp, Hum);
  delay(1000);
} 
