#ifndef HEATFLUX_HPP
#define HEATFLUX_HPP

#include "instationary.hpp"

class HeatFlux : public Instationary
{
public:
    // Constructor
    HeatFlux(const Config &config);

    // Destructor
    ~HeatFlux();

    // solveHeatFlux
    void solveHeatFlux();
};

#endif