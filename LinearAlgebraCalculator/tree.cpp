

template<class T> class tree
{
    int height=0;//length of size
    bool Leaf;
    int* size;//description of how to index lower nodes
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

    std::vector<tree> nodes; //empty if leaf

    std::vector<T> leaves; //empty if not leaf

    bool Leaf;
    int* size;

    tree(bool leaf, int dim, int* size)
    {
        height=dim;
        Leaf = leaf;

        for(int i=0;i<size[0];i++)
        {
            if(Leaf)
            {
                leaves.push_back((T)0)
            }
            else
            //TODO spawn subtree thread to do this
            v.push_back(tree(dim==1,dim-1,&size[1]));
        }

        //wait for subtree threads
    }

    //create from array like
    tree(bool leaf, int dim, int* size, void* elements)
    {
    }
    
    //return true if this node is a 1d list of elements
    //contains no sub trees ie. nodes is empty
    bool isleaf(){return Leaf;}


    /*return a subtree with dimentions height-len(index)
    if index is too long return the leaf node addressed
    by the first height indicies*/
    tree getNode(int* index)
    {
        tree node = this;
        int depth=0;
        int i=0;
        while(index[i+1] != 0 && !node.isleaf())
        {
            node = node.nodes[index[i]]
            i++;
        }
        return node;
    }

    //length of index must equal (height) number of dimentions
    T getLeaf(int* index)
    {
        T item = 0;
        tree node = getNode(index);
        if(node.isleaf())
        {
            //last index gets a 0 dim element type T if enough indicies are given
            item = node.leaves[index[height-1]]
        }

        return item;
    }

    int* getSize()
    {
        return size;
    }

    int getheight()
    {
        return height;
    }
}