#include Tensor.h

Tensor::Tensor(int* sizes,int* dim)
{
    sizes = sizes;
    int i,sum =0;
    while(sizes[i++]!=0)
    {
        sum+=sizes[i];
    }
    void* tensor = malloc(sizeof(T)sum);
}

Tensor::append(int* sizes,int dim);
{
void* tensor = malloc(sizeof(T)*sum);
}

Tensor::transpose()
{
    for()
    {

    }
}

T get(int* index
{
    return tensor[getindex(0,subindicies)];
}

int getindex(int i,subindicies)
{
    if(i==sum)
    {
        return sizes[i]*subindicies[i];
    }
    return sizes[i]*subindicies[i]+getindex(i++); 
}

Tensor Tensor::operator + (Tensor v1, Tensor v2)
{

}

Tensor Tensor::operator * (Tensor v1, Tensor v2)
{

}

Tensor Tensor::operator / (Tensor v1, Tensor v2)
{

}



char* toString();

Tensor::~Tensor()
{
    free(tensor);
}