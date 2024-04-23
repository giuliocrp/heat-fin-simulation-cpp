#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class Vector
{
private:
    int M_size;
    T *M_vec;

public:
    // Constructors
    Vector(int size);

    Vector(int size, T *vec);

    Vector(const Vector<T> &other);

    // Destructor
    ~Vector();

    // Getters
    int getSize() const;
    T getVal(int i) const;

    // Setters
    void setVal(T val, int i);

    // Operators
    T &operator[](int i);
    T const &operator[](int i) const;

    Vector &operator+=(Vector const &v);
    Vector &operator-=(Vector const &v);
    Vector operator+(Vector const &v) const;
    Vector operator-(Vector const &v) const;
    Vector &operator=(Vector const &v);

    // Friend function for output
    friend std::ostream &operator<<(std::ostream &o, Vector const &v);
};

// Constructors definition
template <typename T>
Vector<T>::Vector(int size) : M_size(size), M_vec(new T[M_size])
{
    for (size_t i = 0; i < M_size; i++)
    {
        M_vec[i] = T();
    }
}

template <typename T>
Vector<T>::Vector(int size, T *vec) : M_size(size), M_vec(new T[size])
{
    for (int i = 0; i < M_size; i++)
    {
        M_vec[i] = vec[i];
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T> &other) : M_size(other.M_size), M_vec(new T[M_size])
{
    for (int i = 0; i < M_size; i++)
    {
        M_vec[i] = other.M_vec[i];
    }
}

// Destructor definition
template <typename T>
Vector<T>::~Vector()
{
    delete[] M_vec;
}

// Getters definition
template <typename T>
int Vector<T>::getSize() const { return M_size; }

template <typename T>
T Vector<T>::getVal(int i) const { return M_vec[i]; }

// Setter definition
template <typename T>
void Vector<T>::setVal(T val, int i) { M_vec[i] = val; }

// Operators definition
template <typename T>
T &Vector<T>::operator[](int i) { return M_vec[i]; }

template <typename T>
T const &Vector<T>::operator[](int i) const { return M_vec[i]; }

template <typename T>
Vector<T> &Vector<T>::operator+=(Vector const &v)
{
    if (M_size != v.M_size)
    {
        std::cerr << "Invalid operator+=: Vectors must be of the same size.\n";
        return *this;
    }

    for (int i = 0; i < M_size; ++i)
    {
        M_vec[i] += v.M_vec[i];
    }

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator-=(Vector const &v)
{
    if (M_size != v.M_size)
    {
        std::cerr << "Invalid operator-=: Vectors must be of the same size.\n";
        return *this;
    }

    for (int i = 0; i < M_size; ++i)
    {
        M_vec[i] -= v.M_vec[i];
    }

    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator+(Vector const &v) const
{
    if (M_size != v.M_size)
    {
        std::cerr << "Invalid operator+: Vectors must be of the same size.\n";
        return *this;
    }

    Vector res(M_size);
    for (int i = 0; i < M_size; ++i)
    {
        res.M_vec[i] = M_vec[i] + v.M_vec[i];
    }

    return res;
}

template <typename T>
Vector<T> Vector<T>::operator-(Vector const &v) const
{
    if (M_size != v.M_size)
    {
        std::cerr << "Invalid operator-: Vectors must be of the same size.\n";
        return *this;
    }

    Vector res(M_size);
    for (int i = 0; i < M_size; ++i)
    {
        res.M_vec[i] = M_vec[i] - v.M_vec[i];
    }

    return res;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector const &v)
{
    if (this != &v)
    {
        if (M_size != v.M_size)
        {
            std::cerr << "Invalid assignment: Vectors must be of the same size.\n";
            return *this;
        }

        for (int i = 0; i < M_size; ++i)
        {
            M_vec[i] = v.M_vec[i];
        }
    }

    return *this;
}

// Friend function for output definition
template <typename T>
std::ostream &operator<<(std::ostream &o, Vector<T> const &v)
{
    for (int i = 0; i < v.getSize(); i++)
    {
        o << v[i] << " ";
    }
    return o;
}

#endif
