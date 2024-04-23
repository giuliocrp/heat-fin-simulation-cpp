#include <cmath>
#include <iostream>
#include <string>
#include <filesystem>

#include "stationary.hpp"

// Constructor definition
Stationary::Stationary(const Config &config) : config(config), M_A(config.getM() + 1), M_F(config.getM() + 1), M_X(config.getM() + 1), M_Texact(config.getM() + 1)
{
    BuildMatrix();
    BuildVector();
    BuildTexact();

    solve1DStationaryModel();
    std::string output_folder = "../results/";
    if (!std::filesystem::exists(output_folder)) {
        std::filesystem::create_directory(output_folder);
    }
    visualize1DSolution("../results/stationary1D.csv");
}

// Destructor definition
Stationary::~Stationary() {}

// Getter for the Tridiag M_A
Tridiag<double> Stationary::getA() const { return M_A; }

// Getter for the Vector M_F
Vector<double> Stationary::getF() const { return M_F; }

// BuildMatrix
void Stationary::BuildMatrix()
{
    double h = static_cast<double>(config.getLx()) / static_cast<double>(M_A.getSize());
    double p = 2. * (static_cast<double>(config.getLy()) + static_cast<double>(config.getLz()));
    double S = static_cast<double>(config.getLy()) * static_cast<double>(config.getLz());

    double x1 = (static_cast<double>(config.getK()) / h);
    double x2 = ((2. * static_cast<double>(config.getK())) / std::pow(h, 2)) + ((static_cast<double>(config.getHc()) * p) / S);
    double x3 = -(static_cast<double>(config.getK()) / std::pow(h, 2));

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
void Stationary::BuildVector()
{
    double p = 2 * (config.getLy() + config.getLz());
    double S = config.getLy() * config.getLz();

    double res = (config.getHc() * p * config.getTe()) / S;

    M_F[0] = config.getPhi();
    M_F[M_F.getSize() - 1] = 0;

    for (int i = 1; i < M_F.getSize(); i++)
    {
        M_F[i] = res;
    }
}

// BuildTexact
void Stationary::BuildTexact()
{
    double p = 2 * (config.getLy() + config.getLz());
    double S = config.getLy() * config.getLz();
    double a = (config.getHc() * p) / (config.getK() * S);

    double h = config.getLx() / M_Texact.getSize();

    for (int i = 0; i < M_Texact.getSize(); i++)
    {
        M_Texact[i] = config.getTe() +
                      (config.getPhi() / config.getK()) *
                          ((cosh(sqrt(a) * config.getLx())) / (sqrt(a) * sinh(sqrt(a) * config.getLx()))) *
                          (cosh(sqrt(a) * (config.getLx() - (i * h)))) / cosh(sqrt(a) * config.getLx());
    }
}

// solve1DStationaryModel definition
void Stationary::solve1DStationaryModel()
{
    Solver Stationary1D(M_A, M_F);
    M_X = Stationary1D.getSolution();
}

// visualize1DSolution definition
void Stationary::visualize1DSolution(const std::string &fileName)
{
    int M = config.getM();
    double h = config.getLx() / M_A.getSize();

    std::ofstream ofile(fileName);
    if (!ofile.is_open())
    {
        std::cerr << "Unable to open file: " << fileName << std::endl;
        return;
    }

    ofile << "x, sol1, sol2\n";
    for (int i = 0; i < M; i++)
    {
        ofile << i * h << ", " << M_X.getVal(i) << ", " << M_Texact.getVal(i) << "\n";
    }
}
