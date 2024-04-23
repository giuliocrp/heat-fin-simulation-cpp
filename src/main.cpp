#include <iostream>

#include "vector.hpp"
#include "tridiag.hpp"
#include "mesh.hpp"
#include "config.hpp"
#include "solver.hpp"
#include "stationary.hpp"
#include "instationary.hpp"
#include "constantFlux.hpp"
#include "heatFlux.hpp"

int main(int argc, char **argv)
{
    Config config("../simu.cfg");

    Mesh mesh(config);
    Stationary stationary(config);

    return 0;
}