#include "electriccar.h"

ElectricCar::ElectricCar() {

}

void ElectricCar::accelerate(const float seconds) {
    setSpeed(getSpee() + mAcceleration*(seconds/3600))
}