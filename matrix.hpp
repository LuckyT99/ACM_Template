#include <iostream>

//template <class Elem>
typedef long long Elem;

class matrix
{
  private:
    unsigned int row, col, size;
    Elem *mat;

  public:
    matrix();
    matrix(unsigned int rows);
    matrix(unsigned int rows, unsigned int cols, Elem val = 0);
    matrix(unsigned int rows, unsigned int cols, Elem *arr);
    matrix(unsigned int rows, unsigned int cols, Elem **arr);
    matrix(const matrix &val);
    ~matrix();
    unsigned int getRow() const;
    unsigned int getColumn() const;
    unsigned int getSize() const;
    bool rerange(unsigned int rows, unsigned int cols);
    void setElem(unsigned int rows, unsigned int cols, Elem val);
    Elem getElem(unsigned int rows, unsigned int cols) const;
    Elem *operator[](unsigned int rows);
    matrix T();
    matrix &operator=(const matrix &rhs);
    matrix &operator+=(const matrix &rhs);
    matrix &operator-=(const matrix &rhs);
    matrix &operator*=(const matrix &rhs);
    matrix &operator+=(Elem rhs);
    matrix &operator-=(Elem rhs);
    matrix &operator*=(Elem rhs);
    friend const matrix operator+(const matrix &lhs, const matrix &rhs);
    friend const matrix operator-(const matrix &lhs, const matrix &rhs);
    friend const matrix operator*(const matrix &lhs, const matrix &rhs);
    friend const matrix operator+(const matrix &lhs, Elem rhs);
    friend const matrix operator+(Elem lhs, const matrix &rhs);
    friend const matrix operator-(const matrix &lhs, Elem rhs);
    friend const matrix operator-(Elem lhs, const matrix &rhs);
    friend const matrix operator*(const matrix &lhs, Elem rhs);
    friend const matrix operator*(Elem lhs, const matrix &rhs);
    friend const std::ostream &operator<<(std::ostream &os, const matrix &rhs);
};

//-----------------------------------------------------------------------------

matrix::matrix()
{
    row = 0;
    col = 0;
    size = row * col;
    mat = nullptr;
}
matrix::matrix(unsigned int rows)
{
    row = rows;
    col = rows;
    size = row * col;
    mat = new Elem[size];
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            mat[i * col + j] = (i == j ? 1 : 0);
        }
    }
}
matrix::matrix(unsigned int rows, unsigned int cols, Elem val = 0)
{
    row = rows;
    col = cols;
    size = col * row;
    mat = new Elem[size];
    for (int i = 0; i < size; ++i)
    {
        mat[i] = val;
    }
}
matrix::matrix(unsigned int rows, unsigned int cols, Elem *arr)
{
    row = rows;
    col = cols;
    size = col * row;
    mat = new Elem[size];
    for (int i = 0; i < size; ++i)
    {
        mat[i] = arr[i];
    }
}
matrix::matrix(unsigned int rows, unsigned int cols, Elem **arr)
{
    row = rows;
    col = cols;
    size = col * row;
    mat = new Elem[size];
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            mat[i * col + j] = arr[i][j];
        }
    }
}
matrix::matrix(const matrix &val)
{
    col = val.col;
    row = val.row;
    size = val.size;
    mat = new Elem[size];
    for (int i = 0; i < size; ++i)
    {
        mat[i] = val.mat[i];
    }
}
matrix::~matrix()
{
    delete[] mat;
}
unsigned int matrix::getRow() const
{
    return row;
}
unsigned int matrix::getColumn() const
{
    return col;
}
unsigned int matrix::getSize() const
{
    return size;
}
bool matrix::rerange(unsigned int rows, unsigned int cols)
{
    if (rows * cols == size)
    {
        col = cols;
        row = rows;
        return true;
    }
    else
    {
        return false;
    }
}
void matrix::setElem(unsigned int rows, unsigned int cols, Elem val)
{
    mat[(rows - 1) * cols + (cols - 1)] = val;
}
Elem matrix::getElem(unsigned int rows, unsigned int cols) const
{
    return mat[(rows - 1) * cols + (cols - 1)];
}
Elem *matrix::operator[](unsigned int rows)
{
    return &mat[(rows - 1) * col];
}
matrix matrix::T()
{
    matrix tmp(col, row);
    for (int i = 1; i <= col; ++i)
    {
        for (int j = 1; j <= row; ++j)
        {
            tmp[i][j] = getElem(j, i);
        }
    }
    return tmp;
}
matrix &matrix::operator=(const matrix &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    row = rhs.row;
    col = rhs.col;
    size = rhs.size;
    if (mat != nullptr)
    {
        delete[] mat;
    }
    mat = new Elem[size];
    for (int i = 0; i < size; ++i)
    {
        mat[i] = rhs.mat[i];
    }
}
matrix &matrix::operator+=(const matrix &rhs)
{
    if (row == rhs.row && col == rhs.col)
    {
        for (int i = 0; i < size; ++i)
        {
            mat[i] += rhs.mat[i];
        }
    }
    return *this;
}
matrix &matrix::operator-=(const matrix &rhs)
{
    if (row == rhs.row && col == rhs.col)
    {
        for (int i = 0; i < size; ++i)
        {
            mat[i] -= rhs.mat[i];
        }
    }
    return *this;
}
matrix &matrix::operator*=(const matrix &rhs)
{
    if (col == rhs.row)
    {
        *this = *this * rhs;
    }
    return *this;
}
matrix &matrix::operator+=(Elem rhs)
{
    for (int i = 0; i < size; ++i)
    {
        mat[i] += rhs;
    }
    return *this;
}
matrix &matrix::operator-=(Elem rhs)
{
    for (int i = 0; i < size; ++i)
    {
        mat[i] -= rhs;
    }
    return *this;
}
matrix &matrix::operator*=(Elem rhs)
{
    for (int i = 0; i < size; ++i)
    {
        mat[i] *= rhs;
    }
    return *this;
}
const matrix operator+(const matrix &lhs, const matrix &rhs)
{
    if (lhs.row == rhs.row && lhs.col == rhs.col)
    {
        matrix tmp = lhs;
        tmp += rhs;
        return tmp;
    }
    else
    {
        matrix tmp;
        return tmp;
    }
}
const matrix operator-(const matrix &lhs, const matrix &rhs)
{
    if (lhs.row == rhs.row && lhs.col == rhs.col)
    {
        matrix tmp = lhs;
        tmp -= rhs;
        return tmp;
    }
    else
    {
        matrix tmp;
        return tmp;
    }
}
const matrix operator*(const matrix &lhs, const matrix &rhs)
{
    if (lhs.col == rhs.row)
    {
        matrix tmp(lhs.col, lhs.col);
        for (int i = 1; i <= lhs.row; ++i)
        {
            for (int j = 1; j <= rhs.col; ++j)
            {
                Elem sum = 0;
                for (int k = 1; k <= lhs.col; ++k)
                {
                    sum += lhs.getElem(i, k) * rhs.getElem(k, j);
                }
                tmp[i][j] = sum;
            }
        }
        return tmp;
    }
    else
    {
        matrix tmp;
        return tmp;
    }
}
const matrix operator+(const matrix &lhs, Elem rhs)
{
    matrix tmp = lhs;
    tmp += rhs;
    return tmp;
}
const matrix operator+(Elem lhs, const matrix &rhs)
{
    matrix tmp = rhs;
    tmp += lhs;
    return tmp;
}
const matrix operator-(const matrix &lhs, Elem rhs)
{
    matrix tmp = lhs;
    tmp -= rhs;
    return tmp;
}
const matrix operator-(Elem lhs, const matrix &rhs)
{
    matrix tmp = rhs;
    tmp -= lhs;
    return tmp;
}
const matrix operator*(const matrix &lhs, Elem rhs)
{
    matrix tmp = lhs;
    tmp *= rhs;
    return tmp;
}
const matrix operator*(Elem lhs, const matrix &rhs)
{
    matrix tmp = rhs;
    tmp *= lhs;
    return tmp;
}
const std::ostream &operator<<(std::ostream &os, const matrix &rhs)
{
    if (rhs.mat != nullptr)
    {
        for (int i = 1; i <= rhs.row; ++i)
        {
            os << rhs.getElem(i, 1);
            for (int j = 2; j <= rhs.col; ++j)
            {
                os << ' ' << rhs.getElem(i, j);
            }
            os << std::endl;
        }
    }
    return os;
}