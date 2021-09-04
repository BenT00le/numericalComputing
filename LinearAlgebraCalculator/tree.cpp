
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


    tree<T>::tree(bool leaf, int dim, int* size)
    {
        height=dim;
        Leaf = leaf;
        size = size;

        nodes = std::vector<tree<T>>() ;
        leaves = std::vector<T>();

        for(int i=0;i<size[0];i++)
        {
            if(Leaf)
            {
                leaves.push_back((T)0);
            }
            else
            //TODO spawn subtree thread to do this
            nodes.push_back(tree(dim==1,dim-1,&size[1]));
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
        while(index[i+1] != 0 && !node.isleaf())
        {
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
        tree node = getNode(index);
        if(node.isleaf())
        {
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
        tree node = this;
        int depth=0;
        int i=0;
        while(index[i+1] != 0 && !node.isleaf())
        {
            node = node.nodes[index[i]];
            i++;
        }
        
    }


int main(int argc, char** argv)
{
    int size[3] = {3,3,3};
    int ind[3] = {0,0,0};
    tree<int> test = tree<int>(false, 2, size);

    std::cout<<"test tree 0\n" << test.getLeaf(ind)<<std::endl;
    for(int i=0,j=0,k=0;i<3;i++,j=0)
    {
        while(j<3)
        {
            while(k<3)
            {
                ind[0]=i;
                ind[1]=j;
                ind[2]=k;
                test.setLeaf(ind,k);
                std::cout<<k<<" "
                <<ind[0]<<" "
                <<ind[1]<<" "
                <<ind[2]<<"\ntest tree\n" 
                << test.getLeaf(ind)<<std::endl;
            k++;
            }
        k=0;
        j++;
        }
    }
    return 0;

}