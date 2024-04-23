#include "config.hpp"

// Constructor definition
Config::Config(std::string filename)
{
    std::ifstream ifile(filename);
    if (ifile)
    {
        char c;
        ifile >> c >> c >> M_Lx;
        M_Lx *= 1.e-3;
        ifile >> c >> c >> M_Ly;
        M_Ly *= 1.e-3;
        ifile >> c >> c >> M_Lz;
        M_Lz *= 1.e-3;
        ifile >> c >> M_M;
        ifile >> c >> c >> c >> M_Phi;
        M_Phi *= 1.e6;
        ifile >> c >> c >> M_Hc;
        M_Hc *= 1.e6;
        ifile >> c >> c >> M_Te;
        ifile >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> stationary;
        ifile >> c >> c >> c >> c >> c >> c >> M_TFinal;
        ifile >> c >> M_N;
        ifile >> c >> c >> M_Mx;
        ifile >> c >> c >> M_My;
        ifile >> c >> c >> M_Mz;
    }
    else
    {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
}

// Destructor definition
Config::~Config() {}

// Getters definition
double Config::getLx() const { return M_Lx; }

double Config::getLy() const { return M_Ly; }

double Config::getLz() const { return M_Lz; }

int Config::getM() const { return M_M; }

double Config::getPhi() const { return M_Phi; }

double Config::getHc() const { return M_Hc; }

int Config::getTe() const { return M_Te; }

int Config::getTFinal() const { return M_TFinal; }

int Config::getN() const { return M_N; }

int Config::getMx() const { return M_Mx; }

int Config::getMy() const { return M_My; }

int Config::getMz() const { return M_Mz; }

int Config::getRho() const { return M_Rho; }

int Config::getCp() const { return M_Cp; }

int Config::getK() const { return M_k; }