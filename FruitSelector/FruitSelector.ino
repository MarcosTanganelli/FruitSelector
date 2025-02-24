#include "UltrassonicSensor.hpp"
#include "Motor.hpp"
#include "ComunicationPort.hpp"
#include <Servo.h>

#define TRIGGER 4
#define ECHO 5
#define MAX_DIST 15

#define STEP 7
#define DIR 6

Motor MotorPassos(DIR, STEP);
UltrassonicSensor UltraSensor(MAX_DIST, ECHO, TRIGGER);
ComunicationPort Com;
Servo meuServo;

bool triggerFired = false;           // Indicates if TRIGGER was already sent
unsigned long triggerTimestamp = 0;  // Time when TRIGGER was sent
const unsigned long triggerDelay = 5000; // Delay in milliseconds
bool sensorDisabled = 0;

// Variáveis para lidar oom a fruta
enum Fruit4State { NONE, STOPPED, REVERSE, DONE };
Fruit4State fruit4State = NONE;
unsigned long stateTimestamp = 0;
const unsigned long reverseDuration = 7000; // Run backwards for 7 seconds
const unsigned long shortDelay = 2000;       // Short delay between transitions

void setup() {
  Serial.begin(115200);
  meuServo.attach(3);
  MotorPassos.StartMotor(); // Start the motor initially
}

void loop() {
  // Fruit recognition (if any)
  int Fruit = Com.ReceivedFruits();
  if (Fruit == 1) {
    Serial.println("Fruta 1 reconhecida");
    meuServo.write(45);
  } else if (Fruit == 2) {
    Serial.println("Fruta 2 reconhecida");
    meuServo.write(90);
  } else if (Fruit == 0) {
    Serial.println("Fruta 3 reconhecida");
    meuServo.write(135);
  }
  else if (Fruit == 4){
    Serial.println("Fruit 4 detected: Stopping motor. \n");
    MotorPassos.StopMotor();
    fruit4State = STOPPED;
    stateTimestamp = millis();

    while (millis() - stateTimestamp <= 10000)
    {
      MotorPassos.ReverseMotor();
    }
    
    MotorPassos.StartMotor();
  }

  // if(fruit4State == STOPPED){
  //   if(millis() - stateTimestamp >= shortDelay){
  //     Serial.println("Começando a girar o motor ao contrário \n");
  //     MotorPassos.ReverseMotor();
  //     fruit4State = REVERSE;
  //     stateTimestamp = millis();
  //   }
  // }else if(fruit4State = REVERSE){
  //   if(millis() - stateTimestamp >= shortDelay){
  //     //Serial.println("Se passaram 7 segundos, motor voltando ao normal... \n");
  //     MotorPassos.StopMotor();
  //     fruit4State = DONE;
  //     stateTimestamp = millis();
  //   }
  // }else if(fruit4State == DONE){
  //   if(millis() - stateTimestamp >= shortDelay){
  //     Serial.println("Motor voltando à operação normal... \n");
  //     MotorPassos.StartMotor();
  //     fruit4State = NONE;
  //   }
  // }

  // if(fruit4State == NONE || fruit4State == REVERSE){
  //   //MotorPassos.RunMotor();
  // }

  // If a trigger event is active, check if the delay has passed
  if (triggerFired) {
    if (millis() - triggerTimestamp >= triggerDelay) {
      Serial.println("Delay encerrado. Reiniciando o motor.");
      triggerFired = false;         // Reset trigger flag
    }
    if(millis() - triggerTimestamp >= triggerDelay/2){
      MotorPassos.RunMotor();       
    }
  } else {
    if (UltraSensor.StopMotor()) {
      MotorPassos.StopMotor();      
      Serial.println("TRIGGER");
      triggerFired = true;
      triggerTimestamp = millis();  // Start the non-blocking timer
    } else {
      // If the sensor is not activated and no trigger is active, ensure the motor is running.
      MotorPassos.RunMotor();
    }
  }
}
