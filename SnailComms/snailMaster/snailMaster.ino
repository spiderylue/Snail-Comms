void setup() {
  Serial.begin(9600);
  Serial.println("SnailComms is booting");
  
  SetupDisplay();
  SetupThermoHumid();
  SetupHygrometer();
}

void loop() {

  float Temp = GetTemp();
  float Hygro = GetHygro();
  float Hum = GetHumid();

  ClearDisplay();
  UpdateDisplay(0, Hygro, Temp, Hum);
  
 // UpdateDisplay(1, Hygro, Temp, Hum);
  delay(1000);
}
