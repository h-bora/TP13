#include "RLcircuit.h"
#include <cmath>

RLcircuit::RLcircuit() {
    dt = 0.01;     // �ð� ���� 10ms
    steps = 100;   // 1�ʱ��� �ùķ��̼�
}

void RLcircuit::simulate(double r, double l, double vin) {
    R = r;
    L = l;
    Vin = vin;

    timeArray.clear();
    voltageArray.clear();
    currentArray.clear();
    powerArray.clear();

    for (int i = 0; i < steps; ++i) {
        double t = i * dt;
        double i_t = (Vin / R) * (1 - exp(-R * t / L));     // ���� i(t)
        double v_t = Vin - i_t * R;                          // ��������(���� ����): V - iR
        double p_t = Vin * i_t;                              // ���� P(t)

        timeArray.push_back(t);
        currentArray.push_back(i_t);
        voltageArray.push_back(v_t);
        powerArray.push_back(p_t);
    }
}

const std::vector<double>& RLcircuit::getTimeArray() const {
    return timeArray;
}

const std::vector<double>& RLcircuit::getVoltageArray() const {
    return voltageArray;
}

const std::vector<double>& RLcircuit::getCurrentArray() const {
    return currentArray;
}

const std::vector<double>& RLcircuit::getPowerArray() const {
    return powerArray;
}