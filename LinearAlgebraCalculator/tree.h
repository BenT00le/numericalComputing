
#include <vector>
template<class T> class tree
{

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
    private:
        int height=0;//length of size
        bool Leaf;
        int* size;//description of how to index lower nodes
        
        std::vector<tree> nodes; //empty if leaf

        std::vector<T> leaves; //empty if not leaf

    public: 
        tree<T>(bool leaf, int dim, int* size);

        /*create from array like
        tree(bool leaf, int dim, int* size, void* elements)*/
        
        //return true if this node is a 1d list of elements
        //contains no sub trees ie. nodes is empty
        bool isleaf();


        /*return a subtree with dimentions height-len(index)
        if index is too long return the leaf node addressed
        by the first height indicies*/
        tree getNode(int* index);

        //length of index must equal (height) number of dimentions
        T getLeaf(int* index);




        bool setLeaf(int* index, T val);


        tree setNode(int* index, tree n);



        int* getSize()
        {
            return size;
        };

        int getheight()
        {
            return height;
        };


};