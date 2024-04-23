#include "constantFlux.hpp"

// Constructor definition
ConstantFlux::ConstantFlux(const Config &config) : Instationary(config)
{
    solveConstantFlux();
}

// Destructor definition
ConstantFlux::~ConstantFlux() {}

// solveConstantFlux definition
void ConstantFlux::solveConstantFlux()
{
    Solver solver(M_A, M_F);
    for (int n = 0; n < config.getN(); n++)
    {
        M_X[n]->operator=(solver.getSolution());
    }
}