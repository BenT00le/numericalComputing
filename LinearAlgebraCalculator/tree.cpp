
#include "tree.h"
#include <iostream>
template<class T>

    /*
    size = {2,2} => root[n1[L1,L1],n2[L1,L2]] 2x2 matrix
    L1 could be addressed as root[0][0]
    size = {2,2,2} => root[N1[
       R                     n1[L1,L2],n2[L1,L2]
     |   |                   ],
    N1   N2                N2[
   | |  |  |                 n1[L1,L2],n2[L1,L2]
  n1 n2 n1 n1                ]]
 | |
 L1L2 ------- leaves 
 note the size of subtree N1 is {2,2}
    */


    tree<T>::tree(int dim, int* size)
    {
        height=dim;
        Leaf = dim==1;
        size = size;

        nodes = std::vector<tree<T>>() ;
        leaves = std::vector<T>();

        std::cout<<"create tree\n"
        <<Leaf<<"\nsize: "
        <<size[0]<<"\ndim: "
        <<dim<<std::endl;

        for(int i=0;i<size[0];i++)
        {
            if(Leaf)
            {
                std::cout<<" leaf size: "
                <<leaves.size()<<" of "
                <<size[0]<<std::endl;
                leaves.push_back((T)0);
            }
            else
            {
                std::cout<<"\n"<<i<<" make subtree "<<std::endl;
                //TODO spawn subtree thread to do this
                nodes.push_back(tree(dim-1,&size[1]));
            }
        }

        //wait for subtree threads
    }

    /*create from array like
    tree(bool leaf, int dim, int* size, void* elements)
    {
    }*/
    
    //return true if this node is a 1d list of elements
    //contains no sub trees ie. nodes is empty
    template<class T>
    bool tree<T>::isleaf(){return Leaf;}


    /*return a subtree with dimentions height-len(index)
    if index is too long return the leaf node addressed
    by the first height indicies*/
    template<class T>
    tree<T> tree<T>::getNode(int* index)
    {
        tree node = *this;
        int depth=0;
        int i=0;
        
        while(i<height && !node.isleaf())
        {
            //index[i]<size[i]
            node = node.nodes[index[i]];
            i++;
        }
        return node;
    }

    //length of index must equal (height) number of dimentions
    template<class T>
    T tree<T>::getLeaf(int* index)
    {
        T item = 0;
        tree<T> node = getNode(index);
        if(node.isleaf())
        {
            std::cout<<"\nindex: "<<index[height-1]
            <<"\nleaves: "<<node.leaves.size()
            <<"\nitem: "<<node.leaves[index[height-1]]
            <<std::endl;
            //last index gets a 0 dim element type T if enough indicies are given
            item = node.leaves[index[height-1]];
        }

        return item;
    }



    template<class T>
    bool tree<T>::setLeaf(int* index, T val)
    {
        T item = 0;
        bool validindex = false;
        tree node = getNode(index);
        if(node.isleaf())
        {
            //last index gets a 0 dim element type T if enough indicies are given
            node.leaves[index[height-1]] = val;
            validindex = true;
            std::cout<<"insert "<<val<<std::endl;
        }
        return validindex;

    }

    template<class T>
    tree<T> tree<T>::setNode(int* index, tree n)
    {
        tree node = *this;
        int depth=0;
        int i=0;
        while(i<height && !node.isleaf())
        {
            node = node.nodes[index[i]];
            i++;
        }
        
    }


int main(int argc, char** argv)
{
    int a = 10;
    int size[3] = {2,3,3};
    int ind[3] = {0,0,0};
    tree<int> test = tree<int>(3, size);
    std::cout<<"test tree 0\n" << test.getLeaf(ind)<<std::endl;
    /*for(int i=0,j=0,k=0;i<2;i++,j=0)
    {
        while(j<3)
        {
            while(k<3)
            {
                ind[0]=i;
                ind[1]=j;
                ind[2]=k;
                //test.setLeaf(ind,a);
                std::cout
                <<"\nX: "<<ind[0]
                <<"\nY: "<<ind[1]
                <<"\nZ: "<<ind[2]
                <<"\ntest tree Leaf: " 
                << test.getLeaf(ind)<<std::endl;
            k++;
            a++;
            }
        k=0;
        j++;
        }
    }*/
    return 0;

}