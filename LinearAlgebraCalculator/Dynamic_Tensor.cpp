#include Tensor.h
#include tree.cpp
Tensor::Tensor(int Dim,int* sizes)
{
    //sizes with length dim
    // dim=3 size=[3,3,3] cubeic matrix

    tensor = tree(Dim,sizes)

}

tree Tensor::slice(int* sizes)
{
   return tensor.get(sizes);
}

tree Tensor::transpose()
{
    for()
    {

    }
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



char* toString()
{
    bool hasnext=true;
    tree node = tensor;
    int* index = (int*) malloc(node.getSize());
    int i = tensor.getheight();
    while(hasnext)
    {
        if(node.isleaf())
        {
            while()
            {
                node.getLeaf(index);
            }
            index[i]--;
            for (int j =0;i<leaves;i++)
            {
                node = tensor.getNode(index);
                index[j]--;

            }
            node = tensor.getNode(index)
        }
        else
        {
            if()
        }
    }
}








Tensor::append(std::vector<T> element)
{

}

T get(int* index)
{
    std::vector<> v;
    T val;
    for(int i=0;i<dim;i++)
    {
        val=val[index[i]]
    }
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