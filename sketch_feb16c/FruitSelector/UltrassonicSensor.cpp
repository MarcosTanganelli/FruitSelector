#include "UltrassonicSensor.hpp"

UltrassonicSensor::UltrassonicSensor(int maxDist, int pinEcho, int pinTrigger)
    : sonar(pinTrigger, pinEcho, maxDist) {
}

bool UltrassonicSensor::StopMotor() {
    if(sonar.ping_cm() != 0)
        return true;
    else
        return false;
}
