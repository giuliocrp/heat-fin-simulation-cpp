#ifndef TRIDIAG_HPP
#define TRIDIAG_HPP

#include <iostream>

template <typename T>
class Tridiag
{
private:
    int M_size;
    T *M_diag;
    T *M_lower;
    T *M_upper;

public:
    // Constructors
    Tridiag(int size);

    Tridiag(int size, T *diag, T *lower, T *upper);

    Tridiag(const Tridiag<T> &other);

    // Destructor
    ~Tridiag();

    // Getters
    int getSize() const;

    T getValDiag(int i) const;

    T getValLow(int i) const;

    T getValUp(int i) const;

    // Setters
    void setDiag(T val, int i);

    void setLow(T val, int i);

    void setUp(T val, int i);
};

// Constructors definition
template <typename T>
Tridiag<T>::Tridiag(int size) : M_size(size), M_diag(new T[size]), M_lower(new T[size - 1]), M_upper(new T[size - 1])
{
    for (int i = 0; i < M_size; i++)
    {
        M_diag[i] = T();
    }
    for (int i = 0; i < M_size - 1; i++)
    {
        M_lower[i] = T();
        M_upper[i] = T();
    }
}

template <typename T>
Tridiag<T>::Tridiag(int size, T *diag, T *lower, T *upper) : M_size(size), M_diag(new T[size]), M_lower(new T[size - 1]), M_upper(new T[size - 1])
{
    for (int i = 0; i < M_size; i++)
    {
        M_diag[i] = diag[i];
    }
    for (int i = 0; i < M_size - 1; i++)
    {
        M_lower[i] = lower[i];
        M_upper[i] = upper[i];
    }
}

template <typename T>
Tridiag<T>::Tridiag(const Tridiag<T> &other) : M_size(other.M_size), M_diag(new T[M_size]), M_lower(new T[M_size - 1]), M_upper(new T[M_size - 1])
{
    for (int i = 0; i < M_size; i++)
    {
        M_diag[i] = other.M_diag[i];
    }
    for (int i = 0; i < M_size - 1; i++)
    {
        M_lower[i] = other.M_lower[i];
        M_upper[i] = other.M_upper[i];
    }
}

// Destructor definition
template <typename T>
Tridiag<T>::~Tridiag()
{
    delete[] M_diag;
    delete[] M_lower;
    delete[] M_upper;
}

// Getters definition
template <typename T>
int Tridiag<T>::getSize() const { return M_size; }

template <typename T>
T Tridiag<T>::getValDiag(int i) const { return M_diag[i]; }

template <typename T>
T Tridiag<T>::getValLow(int i) const { return M_lower[i]; }

template <typename T>
T Tridiag<T>::getValUp(int i) const { return M_upper[i]; }

// Setters definition
template <typename T>
void Tridiag<T>::setDiag(T val, int i) { M_diag[i] = val; }

template <typename T>
void Tridiag<T>::setLow(T val, int i) { M_lower[i] = val; }

template <typename T>
void Tridiag<T>::setUp(T val, int i) { M_upper[i] = val; }

#endif
