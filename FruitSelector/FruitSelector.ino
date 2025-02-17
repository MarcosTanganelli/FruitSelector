#include "UltrassonicSensor.hpp"
#include "Motor.hpp"
#include "ComunicationPort.hpp"
#include <Servo.h>

Motor MotorPassos(2,3);
UltrassonicSensor UltraSensor(15, 11, 12);
ComunicationPort Com;
Servo meuServo;

void setup() {
  Serial.begin(115200);

  meuServo.attach(6);
  // MotorPassos.StartMotor();
}

void loop() {
  int Fruit = Com.ReceivedFruits();
  // Serial.print("Fruit: ");
  if(Fruit == 1){
    Serial.println(Fruit); 
    meuServo.write(0);
  } else if(Fruit == 2){
    meuServo.write(45);
  }else if(Fruit == 3){
    meuServo.write(90);
  }
  // for (int pos = 0; pos <= 180; pos += 10) {
  //   meuServo.write(pos);
  //   delay(500);
  // }
  //   myServo.SetPos(90);
  //   delay(500);
  //   myServo.SetPos(0);
  //   delay(500);

  // if(UltraSensor.StopMotor()){
  //   Serial.print("PARA!!! \n");
  //   MotorPassos.StopMotor();
  //   // adicionar delay aqui caso necessário e logo depois no final do else
  // }else{
  //   MotorPassos.RunMotor();
  // }        
  // if (Serial.available() > 0) {  // Verifica se recebeu algo
  //   String recebido = Serial.readStringUntil('\n');
  //   MotorPassos.StopMotor();
  //   Serial.print("Recebido: ");
  //   Serial.println(recebido);
  // }     
}
