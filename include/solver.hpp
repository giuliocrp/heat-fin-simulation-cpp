#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <iostream>

#include "tridiag.hpp"
#include "vector.hpp"

class Solver
{
private:
    Tridiag<double> M_A;
    Vector<double> M_F;

    Tridiag<double> M_L;
    Tridiag<double> M_U;

    Vector<double> M_X;
    Vector<double> M_Y;

public:
    // Constructor
    Solver(Tridiag<double> A, Vector<double> F);

    // Destructor
    ~Solver();

    // Getter for the solution vector M_X
    Vector<double> const& getSolution() const;

    // Getter for the the vector M_Y
    Vector<double> const& getY() const;

    // Getter for the Tridiag M_L
    Tridiag<double> const& getL() const;

    // Getter for the Tridiag M_U
    Tridiag<double> const& getU() const;

    // BuildLU
    void BuildLU();

    // Forward
    void Forward();

    // Back
    void Back();
};

#endif
