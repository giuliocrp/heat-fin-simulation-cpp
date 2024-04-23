#include "solver.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    // Test the Solver class

    // Create a Tridiag matrix
    double diag[] = {1.0, 2.0, 3.0};
    double lower[] = {4.0, 5.0};
    double upper[] = {6.0, 7.0};
    Tridiag<double> A(3, diag, lower, upper);

    // Create a Vector for the right-hand side
    double values[] = {10.0, 2.0, 3.0};
    Vector<double> F(3, values);

    // Create a Solver instance
    std::cout << "\nL Test:" << std::endl;
    Solver solver(A, F);

    Tridiag<double> L = solver.getL();
    Tridiag<double> U = solver.getU();

    for (int i = 0; i < L.getSize(); ++i)
    {
        std::cout << "Diag[" << i << "]: " << L.getValDiag(i) << std::endl;
        if (i < L.getSize() - 1)
        {
            std::cout << "Lower[" << i << "]: " << L.getValLow(i) << std::endl;
            std::cout << "Upper[" << i << "]: " << L.getValUp(i) << std::endl;
        }
    }
    std::cout << "\nU Test:" << std::endl;
    for (int i = 0; i < U.getSize(); ++i)
    {
        std::cout << "Diag[" << i << "]: " << U.getValDiag(i) << std::endl;
        if (i < U.getSize() - 1)
        {
            std::cout << "Lower[" << i << "]: " << U.getValLow(i) << std::endl;
            std::cout << "Upper[" << i << "]: " << U.getValUp(i) << std::endl;
        }
    }

    // Get the solution vector
    Vector<double> solution = solver.getSolution();

    // Output the solution vector
    std::cout << "\nSolution Vector:" << std::endl;
    for (int i = 0; i < solution.getSize(); ++i)
    {
        std::cout << "X[" << i << "]: " << solution[i] << std::endl;
    }

    Vector<double> Y = solver.getY();
    std::cout << "\nY:" << std::endl;
    for (int i = 0; i < Y.getSize(); ++i)
    {
        std::cout << "Y[" << i << "]: " << Y[i] << std::endl;
    }

    return 0;
}