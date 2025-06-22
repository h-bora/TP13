// RCcircuit.cpp
#include "pch.h"
#include "RCcircuit.h"
#include <cmath>

RCcircuit::RCcircuit()
    : R(0), C(0), Vin(0), dt(0.01), steps(100)
{
}

void RCcircuit::simulate(double r, double c, double vin) {
    R = r;
    C = c;
    Vin = vin;

    timeArray.clear();
    voltageArray.clear();
    currentArray.clear();
    powerArray.clear();

    for (int i = 0; i < steps; ++i) {
        double t = i * dt;
        double v_t = Vin * (1 - exp(-t / (R * C)));     // 커패시터 전압
        double i_t = (Vin / R) * exp(-t / (R * C));      // 저항에 흐르는 전류
        double p_t = v_t * i_t;                          // 파워

        timeArray.push_back(t);
        voltageArray.push_back(v_t);
        currentArray.push_back(i_t);
        powerArray.push_back(p_t);
    }
}

const std::vector<double>& RCcircuit::getTimeArray() const {
    return timeArray;
}

const std::vector<double>& RCcircuit::getVoltageArray() const {
    return voltageArray;
}

const std::vector<double>& RCcircuit::getCurrentArray() const {
    return currentArray;
}

const std::vector<double>& RCcircuit::getPowerArray() const {
    return powerArray;
}
