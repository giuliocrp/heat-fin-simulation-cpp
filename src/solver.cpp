#include "solver.hpp"

// Constructor definition
Solver::Solver(Tridiag<double> A, Vector<double> F) : M_A(A), M_F(F), M_L(A.getSize()), M_U(A.getSize()), M_X(A.getSize()), M_Y(A.getSize())
{
    BuildLU();
    Forward();
    Back();
}

// Destructor definition
Solver::~Solver() {}

// Getter for the solution vector M_X
Vector<double> const& Solver::getSolution() const { return M_X; }

// Geter for the vector M_Y
Vector<double> const& Solver::getY() const { return M_Y; }

// Getter for the vector M_L
Tridiag<double> const& Solver::getL() const { return M_L; }

// Getter for the Tridiag M_U
Tridiag<double> const& Solver::getU() const { return M_U; }

// BuildLU
void Solver::BuildLU()
{
    int M = M_A.getSize();

    for (int i = 0; i < M; i++)
    {
        M_L.setDiag(1, i);
    }

    M_U.setDiag(M_A.getValDiag(0), 0);
    for (int i = 0; i < M - 1; i++)
    {
        M_L.setLow(M_A.getValLow(i) / M_U.getValDiag(i), i); // ici
        M_U.setUp(M_A.getValUp(i), i);
        M_U.setDiag(M_A.getValDiag(i + 1) - M_L.getValLow(i) * M_U.getValUp(i), i + 1);
        M_U.setLow(0, i);
        M_L.setUp(0, i);
    }
}

// Forward
void Solver::Forward()
{
    int M = M_A.getSize();
    M_Y.setVal(M_F.getVal(0), 0);

    for (int i = 1; i < M; i++)
    {
        M_Y.setVal(M_F.getVal(i) - M_L.getValLow(i - 1) * M_Y.getVal(i - 1), i);
    }
}

// Back
void Solver::Back()
{
    int M = M_A.getSize();
    M_X.setVal(M_Y.getVal(M - 1) / M_U.getValDiag(M - 1), M - 1);

    for (int i = M - 2; i >= 0; i--)
    {
        M_X.setVal((M_Y.getVal(i) - (M_U.getValUp(i) * M_X.getVal(i + 1))) / M_U.getValDiag(i), i);
    }
}
