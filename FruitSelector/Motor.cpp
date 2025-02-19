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
  // Stepper.setAcceleration(50); // Aceleração
  Stepper.setSpeed(1000); // Velocidade regular
}

void Motor::RunMotor() {
    Stepper.runSpeed();
}

void Motor::StopMotor() {
    Stepper.stop();
}