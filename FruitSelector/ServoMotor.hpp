#ifndef ServoMotor_HPP
#define ServoMotor_HPP

#include <Servo.h>
#include <Arduino.h>

class ServoMotor {
private:
    Servo meuServo;

public:
    ServoMotor(int pinDig);
    void SetPos(int newPos);
};
#endif