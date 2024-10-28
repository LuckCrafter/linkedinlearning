#include "pkw.h"

#include <iostream>

PKW::PKW() {

}

void PKW::drive(const float seconds) {
    mPosition += (seconds*getSpeed())/3600;
}

void PKW::showValues() const {
    Fahrzeug::showValues();
    printf("Position is %fm.\n",mPosition*1000);
}

float PKW::getPosition() const {
    return mPosition;
}

float PKW::setPosition(float newPosition) {
    mPosition = newPosition;
}