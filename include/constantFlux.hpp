#ifndef CONSTANT_FLUX_HPP
#define CONSTANT_FLUX_HPP

#include "instationary.hpp"

class ConstantFlux : public Instationary
{
public:
    // Constructor
    ConstantFlux(const Config &config);

    // Destructor
    ~ConstantFlux();

    // solveConstantFlux
    void solveConstantFlux();
};

#endif