#include "stationary.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    // Test the Stationary class

    // Test constructor
    Config config("../simu.cfg");

    Stationary stationary(config);

    // Test the BuildMatrix method
    std::cout << "BuildMatrix Test:" << std::endl;

    Tridiag<double> A = stationary.getA();

    std::cout << "Size: " << A.getSize() << std::endl;
    for (int i = 0; i < A.getSize(); ++i)
    {
        std::cout << "Diag[" << i << "]: " << A.getValDiag(i) << std::endl;
        if (i < A.getSize()-1)
        {
            std::cout << "Lower[" << i << "]: " << A.getValLow(i) << std::endl;
            std::cout << "Upper[" << i << "]: " << A.getValUp(i) << std::endl;
        }
    }

    // Test the BuildVector method
    std::cout << "\nBuildVector Test:" << std::endl;

    Vector<double> F = stationary.getF();

    std::cout << "Size: " << F.getSize() << std::endl;
    for (int i = 0; i < F.getSize(); ++i)
    {
        std::cout << "F[" << i << "]: " << F[i] << std::endl;
    }

    // Test the solve1DStationaryModel method
    std::cout << "\nSolve Test:" << std::endl;
    auto X = stationary.getX();
    std::cout << "Size: " << F.getSize() << std::endl;
    for (int i = 0; i < X.getSize(); ++i)
    {
        std::cout << "X[" << i << "]: " << X[i] << std::endl;
    }
    

    return 0;
}
