/*
 Soil Moisture Sensor  
 modified on 21 Feb 2019 
 by Saeed Hosseini @ Electropeak 
 https://electropeak.com/learn/ 
*/
#define SensorPin A7 
int maxHygrometer = 1006;
int minHygrometer = 283;
float sensorValue = 0;


void setup() { 
 Serial.begin(9600); 
 pinMode(2, OUTPUT);
} 


void loop() { 
 digitalWrite(2, HIGH);
 delay(1000);
 sensorValue = 0;
 for (int i = 0; i <= 100; i++) 
 { 
   sensorValue = sensorValue + analogRead(SensorPin); 
   delay(1); 
 } 
 sensorValue = sensorValue/100.0; 
 Serial.println(sensorValue); 
 digitalWrite(2, LOW);
 delay(2000); 

// float sensorReading =  analogRead(SensorPin);
// float HGoutput = ((sensorReading - minHygrometer) / (maxHygrometer - minHygrometer)) * 100.0;
// Serial.println(HGoutput);
// Serial.println(sensorReading);
// digitalWrite(2, LOW);
// delay(1000);

}


 
 
 
 

//Serial.println(analogRead(SensorPin));
