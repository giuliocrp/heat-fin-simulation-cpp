#include <cmath>

#include "instationary.hpp"

// Constructor definition
Instationary::Instationary(const Config &config) : config(config), M_A(config.getM()), M_F(config.getM())
{
    M_X = new Vector<double> *[config.getN()];
    for (int i = 0; i < config.getN(); i++)
    {
        M_X[i] = new Vector<double>(config.getM());
    }

    BuildMatrix();
    BuildVector();
}

// Destructor definition
Instationary::~Instationary()
{
    for (int i = 0; i < config.getN(); i++)
    {
        delete M_X[i];
    }
    delete[] M_X;
}

// BuildMatrix
void Instationary::BuildMatrix()
{
    double h = static_cast<double>(config.getLx()) / static_cast<double>(M_A.getSize());
    double p = 2. * (static_cast<double>(config.getLy()) + static_cast<double>(config.getLz()));
    double S = static_cast<double>(config.getLy()) * static_cast<double>(config.getLz());
    double dt = static_cast<double>(config.getTFinal()) / static_cast<double>(config.getN());

    double x1 = (static_cast<double>(config.getK()) / h);
    double x2 = (static_cast<double>(config.getRho()) * static_cast<double>(config.getCp())) / dt + 2 * (static_cast<double>(config.getK()) / std::pow(h, 2)) + static_cast<double>(config.getHc()) * p / S;
    double x3 = -(static_cast<double>(config.getRho()) * config.getCp());

    M_A.setDiag(x1, 0);
    M_A.setDiag(x1, M_A.getSize() - 1);
    M_A.setLow(-x1, M_A.getSize() - 2);
    M_A.setUp(-x1, 0);

    for (int i = 1; i < M_A.getSize() - 1; i++)
    {
        M_A.setDiag(x2, i);
    }
    for (int i = 0; i < M_A.getSize() - 2; i++)
    {
        M_A.setLow(x3, i);
        M_A.setUp(x3, i + 1);
    }
}

// BuildVector
void Instationary::BuildVector()
{
    double p = 2 * (config.getLy() + config.getLz());
    double S = config.getLy() * config.getLz();

    double res = (config.getHc() * p * config.getTe()) / S;

    M_F[0] = config.getPhi();
    M_F[M_F.getSize() - 1] = 0;

    for (int i = 1; i < M_F.getSize() - 1; i++)
    {
        M_F[i] = res;
    }
}