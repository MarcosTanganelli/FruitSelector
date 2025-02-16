#include "UltrassonicSensor.hpp"

UltrassonicSensor UltraSensor(15, 11, 12);

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  delay(50);
  if(UltraSensor.StopMotor()){
    Serial.print("PARA!!! \n");
  }else{
    Serial.print("Nada Ainda \n"); 
  }             
}
