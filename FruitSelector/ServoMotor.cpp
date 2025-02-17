#include "ServoMotor.hpp"

ServoMotor::ServoMotor(int pinDig) {
    meuServo.attach(6);
    meuServo.write(0);
}

void ServoMotor::SetPos(int newPos) {
    meuServo.write(newPos);
    // Serial.print("setado");
    // Serial.println(newPos);
    
}