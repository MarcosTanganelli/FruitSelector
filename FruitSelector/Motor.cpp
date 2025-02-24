#include "Motor.hpp"
// #include <AccelStepper.h>

#define InterfaceMotor 1

Motor::Motor(int pinDir, int pinStep)
    : Stepper(InterfaceMotor, pinStep, pinDir) {
    // Stepper.setMaxSpeed(1000);
    // Stepper.setSpeed(500);
}

void Motor::StartMotor() {
  Stepper.setMaxSpeed(1000);   // Velocidade máxima
  Stepper.setSpeed(-150); // Velocidade regular
}

void Motor::RunMotor() {
    Stepper.setMaxSpeed(1000);   // Velocidade máxima
    Stepper.setSpeed(-150); // Velocidade regular
    Stepper.runSpeed();
}

void Motor::ReverseMotor(){
  Stepper.setSpeed(200);
  Stepper.runSpeed();
}

void Motor::StopMotor() {
    Stepper.stop();
}