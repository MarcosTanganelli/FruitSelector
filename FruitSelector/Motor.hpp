#ifndef Motor_HPP
#define Motor_HPP

#include <AccelStepper.h>
#include <Arduino.h>

class Motor {
private:
    AccelStepper Stepper;
public:
    Motor(int pinDir, int pinStep);
    void StartMotor();
    void StopMotor();
    void RunMotor();
    void ReverseMotor();
};
#endif