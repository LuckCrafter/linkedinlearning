#include "dieselcar.h"

DieselCar::DieselCar() {

}

void DieselCar::accelerate(const float seconds) {
    setSpeed(getSpeed() + mAcceleration*(seconds/3600));// TODO: add formula for boosting up here
}