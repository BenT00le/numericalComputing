/*
this class defines a tensor object containing objects of type T with rankV+rankD dimentions
this class can be used as a vector or matrix if v+d=1 or 2 respectively
general operations between tensors may be overrided by vector/matrix subclasses
*/
template<class T> class Tensor
{
private:

    int dim;

    int* sizes;

    tree tensor;
public:


    Tensor(int Dim, int* sizes);

    slice(int v0,int v1, int* dim);

    transpose();

    //append(int* sizes,int dim);

    append(std::vector<T> element);

    //is vector
    //is matrix

    
    //paralell ops
    Tensor operator + (Tensor v1, Tensor v2);

    Tensor operator * (Tensor v1, Tensor v2);

    Tensor operator / (Tensor v1, Tensor v2);



    char* toString();