#pragma once
#include <vector>

class RLcircuit {
private:
    double R;  // ���� (Ohm)
    double L;  // �δ��Ͻ� (H)
    double Vin;  // �Է� ���� (V)
    double dt;  // �ð� ����
    int steps;  // �ùķ��̼� ���� ��

    std::vector<double> timeArray;
    std::vector<double> voltageArray;
    std::vector<double> currentArray;
    std::vector<double> powerArray;

public:
    RLcircuit();
    void simulate(double R, double L, double Vin);
    const std::vector<double>& getTimeArray() const;
    const std::vector<double>& getVoltageArray() const;
    const std::vector<double>& getCurrentArray() const;
    const std::vector<double>& getPowerArray() const;
};