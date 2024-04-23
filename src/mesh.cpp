#include "mesh.hpp"

// Constructor definition
Mesh::Mesh(const Config &config) : config(config)
{
    generateMesh("../results/mesh.vtk");
}

// Destructor definition
Mesh::~Mesh() {}

// Member functions definition
void Mesh::generateMesh(const std::string &fileName)
{
    std::ofstream ofile(fileName);

    writeVTKHeader(ofile);
    writeMeshDimensions(ofile);
    writeMeshPoints(ofile);

    ofile.close();
}

void Mesh::writeVTKHeader(std::ofstream &ofile)
{
    ofile << "# vtk DataFile Version 2.0\nvtk output\nASCII\nDATASET STRUCTURED_GRID\n";
}

void Mesh::writeMeshDimensions(std::ofstream &ofile)
{
    int M_x = config.getMx();
    int M_y = config.getMy();
    int M_z = config.getMz();

    ofile << "DIMENSIONS " << M_x + 1 << " " << M_y + 1 << " " << M_z + 1 << "\n";
}

void Mesh::writeMeshPoints(std::ofstream &ofile)
{
    int M_x = config.getMx();
    int M_y = config.getMy();
    int M_z = config.getMz();

    ofile << "POINTS " << (M_x + 1) * (M_y + 1) * (M_z + 1) << " float\n";

    for (int k = 0; k < M_z + 1; k++)
    {
        for (int j = 0; j < M_y + 1; j++)
        {
            for (int i = 0; i < M_x + 1; i++)
            {
                ofile << i << " " << j << " " << k << "\n";
            }
        }
    }
}