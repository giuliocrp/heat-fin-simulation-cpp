#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Config
{
private:
    double M_Lx, M_Ly, M_Lz;
    int M_M;
    double M_Phi, M_Hc;
    int M_Te;
    bool stationary;
    int M_TFinal;
    int M_N;
    int M_Mx, M_My, M_Mz;

    int M_Rho = 2700;
    int M_Cp = 940;
    int M_k = 164;

public:
    // Constructor
    Config(std::string filename);

    // Destructor
    ~Config();

    // Getters
    double getLx() const;
    double getLy() const;
    double getLz() const;

    int getM() const;

    double getPhi() const;
    double getHc() const;

    int getTe() const;
    int getTFinal() const;
    int getN() const;

    int getMx() const;
    int getMy() const;
    int getMz() const;

    int getRho() const;
    int getCp() const;
    int getK() const;
};

#endif