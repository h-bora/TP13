#pragma once
#include <vector>

class RLcircuit {
private:
    double R;  // 저항 (Ohm)
    double L;  // 인덕턴스 (H)
    double Vin;  // 입력 전압 (V)
    double dt;  // 시간 간격
    int steps;  // 시뮬레이션 스텝 수

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