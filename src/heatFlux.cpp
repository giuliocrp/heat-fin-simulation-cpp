#include "heatFlux.hpp"

// Constructor definition
HeatFlux::HeatFlux(const Config &config) : Instationary(config)
{
    solveHeatFlux();
}

// Destructor definition
HeatFlux::~HeatFlux() {}

// solveHeatFlux definition
void HeatFlux::solveHeatFlux()
{
}