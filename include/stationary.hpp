#ifndef STATIONARY_HPP
#define STATIONARY_HPP

#include <iostream>
#include "config.hpp"
#include "tridiag.hpp"
#include "vector.hpp"
#include "solver.hpp"

class Stationary
{
private:
    const Config &config;
    Tridiag<double> M_A;
    Vector<double> M_F;
    Vector<double> M_X;
    Vector<double> M_Texact;

public:
    // Constructor
    Stationary(const Config &config);

    // Destructor
    ~Stationary();

    // Getter for the Tridiag M_A
    Tridiag<double> getA() const;

    // Getter for the Vector M_F
    Vector<double> getF() const;

    Vector<double> getX() const { return M_X;}


    // BuildMAtrix
    void BuildMatrix();

    // BuildVector
    void BuildVector();

    // BuildTexact
    void BuildTexact();

    // solve1DStationaryModel
    void solve1DStationaryModel();

    // visualize1DSolution
    void visualize1DSolution(const std::string &fileName);
};

#endif
