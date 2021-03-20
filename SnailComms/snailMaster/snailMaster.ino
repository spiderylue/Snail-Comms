#include "ThermoHumidSensor.h"


int HYGROMETER_FRONT_POWERPIN = 2;
int HYGROMETER_FRONT_SENSORPIN = A2;
int HYGROMETER_BACK_POWERPIN = 3;
int HYGROMETER_BACK_SENSORPIN = A3;
int THERMOHUMID_FRONT_PIN = 5;
int THERMOHUMID_BACK_PIN = 6;

ThermoHumidSensor ThermoHumidFront(THERMOHUMID_FRONT_PIN);
ThermoHumidSensor ThermoHumidBack(THERMOHUMID_BACK_PIN);

enum class Mode {
  Readout,
  Snails
};

Mode mode = Mode::Readout;
int displayCount = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("SnailComms is booting");
  
  SetupDisplay();
  SetupSnails();
  SetupHygrometer(HYGROMETER_FRONT_POWERPIN);
  SetupHygrometer(HYGROMETER_BACK_POWERPIN);
}

void loop() {
  
  if (mode == Mode::Readout)
  {
    float TempFront = ThermoHumidFront.GetTemp();
    float TempBack = ThermoHumidBack.GetTemp();
    float HygroFront = GetHygro(HYGROMETER_FRONT_SENSORPIN, HYGROMETER_FRONT_POWERPIN);
    float HygroBack = GetHygro(HYGROMETER_BACK_SENSORPIN, HYGROMETER_BACK_POWERPIN);
    float HumFront = ThermoHumidFront.GetHumid();
    float HumBack = ThermoHumidBack.GetHumid();
  
    ClearDisplay();
    UpdateDisplay(0, HygroFront, TempFront, HumFront);
    UpdateDisplay(1, HygroBack, TempBack, HumBack);
    
    displayCount++;
    if (displayCount == 5)
    {
      displayCount = 0;
      mode = Mode::Snails;
    }
    
    delay(1000);
  }
  else if (mode == Mode::Snails)
  {
    DrawSnails();

    displayCount++;
    if (displayCount == 50)
    {
      displayCount = 0;
      mode = Mode::Readout;
    }
  }
}
