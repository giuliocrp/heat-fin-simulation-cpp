#include "vector.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    // Test the Vector class

    // Test default constructor
    Vector<double> vecDefault(3);
    std::cout << "Default Constructor Test:" << std::endl;
    std::cout << "Size: " << vecDefault.getSize() << std::endl;
    for (int i = 0; i < vecDefault.getSize(); ++i)
    {
        std::cout << "Value[" << i << "]: " << vecDefault[i] << std::endl;
    }

    // Test parameterized constructor
    double values[] = {1.0, 2.0, 3.0};
    Vector<double> vecParam(3, values);
    std::cout << "\nParameterized Constructor Test:" << std::endl;
    std::cout << "Size: " << vecParam.getSize() << std::endl;
    for (int i = 0; i < vecParam.getSize(); ++i)
    {
        std::cout << "Value[" << i << "]: " << vecParam[i] << std::endl;
    }

    // Test copy constructor
    Vector<double> vecCopy(vecParam);
    std::cout << "\nCopy Constructor Test:" << std::endl;
    std::cout << "Size: " << vecCopy.getSize() << std::endl;
    for (int i = 0; i < vecCopy.getSize(); i++)
    {
        std::cout << "Value[" << i << "]: " << vecCopy[i] << std::endl;
    }

    // Test setters
    vecCopy.setVal(10.0, 1);
    vecCopy.setVal(20.0, 0);
    vecCopy.setVal(30.0, 2);

    std::cout << "\nSetters Test:" << std::endl;
    for (int i = 0; i < vecCopy.getSize(); i++)
    {
        std::cout << "Value[" << i << "]: " << vecCopy[i] << std::endl;
    }

    return 0;
}