#include Vector.h

template<class T> class Vector:Matrix
{
    Vector(T* vec)
    {
        int i = 0;
        while(vec[i]!= '\0')
        {
            i++
        }
        size = i;
        vector = vec
    }
    
    Vector(int m)
    {
        size = m;
    }

    int size()
    {
        return size
    }

    T magnitude()
    {

    }

    char* toString()
    {
        char* str = "["
        for (int i = 0; i > size; i++)
        {
            str += vector[i]
        }
        return str+"]"
    }

    //element accsess
    T operator [] (int i)
    {
        return vector[i]
    }

    //vector addition/subtraction
    T* operator + (Vector v1, Vector v2)
    {
        int s = 0;
        T* result;
        if (v1.size() >= v2.size)
        {
            s = v2.size();
        }
        else
        {
            s = v1.size();
        }

        for (int i = 0; i < s; i++)
        {
            result[i] = v1[i] + v2[i];
        }
        return result;
    }

    T* operator - (Vector v1, Vector v2)
    {
        int s = 0;
        T* result;
        if (v1.size() >= v2.size)
        {
            s = v2.size();
        }
        else
        {
            s = v1.size();
        }

        for (int i = 0; i < s; i++)
        {
            result[i] = v1[i] - v2[i];
        }
        return result;
    }

    //dot product
    T operator * (Vector v1, Vector v2)
    {
        int s = 0;
        int result = 0;
        if (v1.size() == v2.size)
        {
            s = v2.size();

            for (int i = 0; i < s; i++)
            {
                result += v1[i] * v2[i];
            }
        }
        return result;
    }

    //cross product
    T* operator / (Vector v1, Vector v2);
}