#include "tridiag.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    // Test the Tridiag class

    // Test default constructor
    Tridiag<double> triDiagDefault(3);
    std::cout << "Default Constructor Test:" << std::endl;
    std::cout << "Size: " << triDiagDefault.getSize() << std::endl;

    // Test parameterized constructor
    double diag[] = {1.0, 2.0, 3.0};
    double lower[] = {4.0, 5.0};
    double upper[] = {6.0, 7.0};
    Tridiag<double> triDiagParam(3, diag, lower, upper);

    std::cout << "\nParameterized Constructor Test:" << std::endl;
    std::cout << "Size: " << triDiagParam.getSize() << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Diag[" << i << "]: " << triDiagParam.getValDiag(i) << std::endl;
        if (i < 2)
        {
            std::cout << "Lower[" << i << "]: " << triDiagParam.getValLow(i) << std::endl;
            std::cout << "Upper[" << i << "]: " << triDiagParam.getValUp(i) << std::endl;
        }
    }

    // Test copy constructor
    Tridiag<double> triDiagCopy(triDiagParam);
    std::cout << "\nCopy Constructor Test:" << std::endl;
    std::cout << "Size: " << triDiagCopy.getSize() << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Diag[" << i << "]: " << triDiagCopy.getValDiag(i) << std::endl;
        if (i < 2)
        {
            std::cout << "Lower[" << i << "]: " << triDiagCopy.getValLow(i) << std::endl;
            std::cout << "Upper[" << i << "]: " << triDiagCopy.getValUp(i) << std::endl;
        }
    }

    // Test setters
    triDiagCopy.setDiag(10.0, 1);
    triDiagCopy.setLow(20.0, 0);
    triDiagCopy.setUp(30.0, 1);

    std::cout << "\nSetters Test:" << std::endl;
    std::cout << "Diag[1] after setting: " << triDiagCopy.getValDiag(1) << std::endl;
    std::cout << "Lower[0] after setting: " << triDiagCopy.getValLow(0) << std::endl;
    std::cout << "Upper[2] after setting: " << triDiagCopy.getValUp(1) << std::endl;

    return 0;
}
