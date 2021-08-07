

template<class T> class tree
{
    int height=0;
    bool Leaf;
    int* size;

    std::vector<tree> v;

    std::vector<T> leaves;

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
            //spawn subtree thread
            v.push_back(tree(dim==1,dim-1,&size[1]));
        }

        //wait for subtree threads
    }

    //create from array like
    tree(bool leaf, int dim, int* size, void* elements)
    {
    }
    
    //return true if this node is a 1d list of elements
    //contains no sub trees ie. v is empty
    bool isleaf(){return Leaf;}


    //return a subtree with dimentions height-len(index)
    tree getNode(int* index)
    {
        tree node = this;
        int depth=0;
        int i=0;
        while(index[i+1] != 0)
        {
            node = node.v[index[i]]
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
            //last index gets a 0 dim element if enough indicies are given
            item = node.leaves[index[i]]
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