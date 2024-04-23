#ifndef MESH_HPP
#define MESH_HPP

#include <iostream>
#include <fstream>
#include "config.hpp"

class Mesh
{
private:
    const Config &config;

public:
    // Constructor
    Mesh(const Config &config);

    // Destructor
    ~Mesh();

    // Member functions
    void generateMesh(const std::string &fileName);

    void writeVTKHeader(std::ofstream &ofile);

    void writeMeshDimensions(std::ofstream &ofile);

    void writeMeshPoints(std::ofstream &ofile);
};

#endif