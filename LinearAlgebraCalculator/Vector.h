template<class T> class Vector:Matrix
{
private:
    int size;
    T* vector; // the vector
public:
    Vector(T* vec);

    Vector(int m);

    int size();

    T magnitude();

    char* toString();

    //element accsess
    T operator [] (int);

    //vector addition/subtraction
    T* operator + (Vector, Vector);

    T* operator - (Vector, Vector);

    //dot product
    // if vector/dual vec === vec(dualvec) * v2
    T operator * (Vector, Vector);

    //cross product
    T* operator / (Vector, Vector);
}