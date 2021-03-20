#define SensorPin A7
#define MAX_HYGROMETER 1006
#define MIN_HYGROMETER 283
#define HygrometerPowerPin 2

float sensorValue = 0;

void SetupHygrometer() {
  pinMode(HygrometerPowerPin, OUTPUT);
}

float GetHygro() {

  // Resistance-based hygrometers will corrode if there is a continuous current
  // whilst the diodes are wet, so we need to control the current

  // Switch on current to power pin and wait 1 second
  digitalWrite(HygrometerPowerPin, HIGH);
  delay(1000);

  // Take an average of 100 readings to smooth data
  sensorValue = 0;
  for (int i = 0; i <= 100; i++)
  {
    sensorValue = sensorValue + analogRead(SensorPin);
    delay(1);
  }
  sensorValue = sensorValue / 100.0;

  // Create a percentage value for humidity
  float HGoutput = ((sensorValue - MIN_HYGROMETER) / (MAX_HYGROMETER - MIN_HYGROMETER)) * 100.0;

  // Switch off current to power pin
  digitalWrite(HygrometerPowerPin, LOW);

  return HGoutput;
}
