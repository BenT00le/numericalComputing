#include Tensor.h

/*
this class defines a matrix object containing objects of type T of size m,n
this class can be used as a vector by defining a matrix of size n,0
this ablility to be used as a vector will be removed when the tensor super class is added
various operations between matricies and vectors will be defined
*/
template<class T> class Matrix:Tensor
{
private:
    rankD = 1;
    rankV = 1;
    int length; // m
    int width; //n
    //use 1,1 tensor T** matrix; // the matrix
public:
    Matrix(int m, int n);

    char* toString();

    Matrix* rowReduce();

    int determinant();

    int length() return length;

    int width() return width;

    // accsessors

    //element accsess
    T& operator [] (int, int);

    //vector acsess by colum
    T* operator < (Matrix const &m1, int i);

    //vector acsess by row (dual vector)
    T* operator > (Matrix const &m1, int i);

    
    //matrix operations


    // matrix addition
    Matrix& operator + (Matrix const &m1, Matrix const &m2);

    // matrix subtraction
    Matrix& operator - (Matrix const &m1, Matrix const &m2);

    //matrix cross product
    Matrix& operator / (Matrix const &m1, Matrix const &m2); 

    // matrix dot product
    Matrix& operator * (Matrix const &m1, Matrix const &m2);


    //scalar operations


    // scalar addition
    Matrix& operator + (Matrix const &m1, int i);

    // scalar subtraction
    Matrix& operator - (Matrix const &m1, int i);

    // scalar division
    Matrix& operator / (Matrix const &m1, int i); 

    // scalar multiplication
    Matrix& operator * (Matrix const &m1, int i);

}