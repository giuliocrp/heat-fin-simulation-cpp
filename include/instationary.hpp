#ifndef INSTATIONARY_HPP
#define INSTATIONARY_HPP

#include <iostream>
#include "config.hpp"
#include "tridiag.hpp"
#include "vector.hpp"
#include "solver.hpp"

class Instationary
{
protected:
    const Config &config;
    Tridiag<double> M_A;
    Vector<double> M_F;
    Vector<double> **M_X;

public:
    // Constructor
    Instationary(const Config &config);

    // Destructor
    ~Instationary();

    // BuildMAtrix
    void BuildMatrix();

    // BuildVector
    void BuildVector();
};

#endif
