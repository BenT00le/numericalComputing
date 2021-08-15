
#include "Tensor.h"
#include "tree.cpp"
int main(int argc char** argv)
{
    test_TensorConstructor();
    return 0;
}

bool test_TensorConstructor()
{
    bool pass = false;
    int* size = {2,2};
    tree root = tree<int>(leaf, 2, size);

    //Tensor t = Tensor(4,{3,3,3,4});

    return pass;
}

bool test_getLeaf()
{
    bool pass = false;
    int* size = {2,2};
    tree root = tree<int>(leaf, 2, size);

    pass = root.getLeaf({1,1}) == 0; //last element initialixed to 0

    return pass
}

bool test_getNode()
{
    bool pass = false;
    int* size = {2,2};
    tree root = tree<int>(leaf, 2, size);

    pass = root.getNode({1});

    return pass
}

//get element of 3x3
bool test_TensorConstructor()
{
    bool pass = false;
    int* size = {3,3};
    tree root = tree<int>(leaf, 2, size,
        {
         {1,2,3},
         {4,5,6},
         {7,8,9}
        });

    return pass;
}
//get 1x3 from 3x3
/*
a00 a01 *a02
a10 a11 *a12
a20 a21 *a22
*/

//get 3x1 from 3x3
/*
*a00 *a01 *a02
a10 a11 a12
a20 a21 a22
*/

//get 2x2 from 3x2 
/*
a00 a01 a02
a10 *a11 *a12
a20 *a21 *a22
*/

//selections from 3x3x3
