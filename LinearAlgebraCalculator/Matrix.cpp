    Martix::Matrix(int m, int n)
    {
        matrix = T[m][n];
        length = m;
        width = n;
    }

    Matrix* Martix::rowReduce(Matrix &m)
    {

    }

    int Martix::determinant()
    {

    }

    // accsessors

    //element accsess
    T& Martix::operator [] (int m, int n)
    {
        return matrix[m][n];
    }

    //vector acsess by colum
    T* Martix::operator < (Matrix const &m1, int i)
    {
        return matrix[i];
    }

    //vector acsess by row
    T* Martix::operator > (Matrix const &m1, int i)
    {
        return matrix[*][i];
    }

    
    //matrix operations


    // matrix addition
    Matrix& Martix::operator + (Matrix const &m1, Matrix const &m2)
    {
        if(m1.length() == m2.length() && m1.width() == m2.width())
        {
            Matrix m3 = Matrix(m1.length(), m1.width());
            for(int i = 0; i < m1.length(); i++)
            {
                for(int j = 0; j < m1.length(); j++)
                {

                }
            }
        }
        
    }

    // matrix subtraction
    Matrix& Martix::operator - (Matrix const &m1, Matrix const &m2)
    {
        if(m1.length() == m2.length() && m1.width() == m2.width())
        {
            Matrix m3 = Matrix(m1.length(), m1.width());
            for(int i = 0; i < m1.length(); i++)
            {
                for(int j = 0; j < m1.length(); j++)
                {

                }
            }
        }
    }

    //matrix cross product
    Matrix& Martix::operator / (Matrix const &m1, Matrix const &m2)
    {
        if(m1.length() == m2.width() && m1.width() == m2.length())
        {
            Matrix m3 = Matrix(m1.length(), m1.width());
            for(int i = 0; i < m1.length(); i++)
            {
                for(int j = 0; j < m1.length(); j++)
                {

                }
            }
        }
    }

    // matrix dot product
    Matrix& Martix::operator * (Matrix const &m1, Matrix const &m2)
    {
        if(m1.length() == m2.width() && m1.width() == m2.length())
        {
            Matrix m3 = Matrix(m1.length(), m1.width());
            for(int i = 0; i < m1.length(); i++)
            {
                for(int j = 0; j < m1.length(); j++)
                {

                }
            }
        }
    }


    //scalar operations


    // scalar addition
    Matrix& Martix::operator + (Matrix const &m1, int i)
    {

    }

    // scalar subtraction
    Matrix& Martix::operator - (Matrix const &m1, int i)
    {

    }

    // scalar division
    Matrix& Martix::operator / (Matrix const &m1, int i)
    {

    }

    // scalar multiplication
    Matrix& Martix::operator * (Matrix const &m1, int i)
    {

    }