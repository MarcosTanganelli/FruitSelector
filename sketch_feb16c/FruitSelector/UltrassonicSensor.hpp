#ifndef UltrassonicSensor_HPP
#define UltrassonicSensor_HPP

#include <NewPing.h>
#include <Arduino.h>

class UltrassonicSensor {
private:
    NewPing sonar;
public:
    UltrassonicSensor(int maxDist,  int pinEcho, int pinTrigger);
    bool StopMotor();
};

#endif