#pragma once
#include <vector>

class RCcircuit {
private:
    double R;  // ���� (Ohm)
    double C;  // Ŀ�н��Ͻ� (F)
    double Vin;  // �Է� ���� (V)
    double dt;  // �ð� ����
    int steps;  // �ùķ��̼� ���� ��

    std::vector<double> timeArray;
    std::vector<double> voltageArray;
    std::vector<double> currentArray;
    std::vector<double> powerArray;

public:
    RCcircuit();
    void simulate(double R, double C, double Vin);
    const std::vector<double>& getTimeArray() const;
    const std::vector<double>& getVoltageArray() const;
    const std::vector<double>& getCurrentArray() const;
    const std::vector<double>& getPowerArray() const;
};
