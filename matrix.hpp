#include <iostream>

//template <class Elem>
typedef int Elem;

class matrix
{
  private:
    unsigned int row, col, size;
    Elem *mat;

  public:
    matrix();
    matrix(int rows);
    matrix(int rows, int cols, Elem val = 0);
    matrix(int rows, int cols, Elem *arr);
    matrix(int rows, int cols, Elem **arr);
    matrix(const matrix &val);
    ~matrix();
    unsigned int getRow() const;
    unsigned int getColumn() const;
    unsigned int getSize() const;
    bool rerange(int rows, int cols);
    void setElem(int rows, int cols, Elem val);
    Elem getElem(int rows, int cols) const;
    Elem *operator[](int rows);
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
    friend std::ostream &operator<<(std::ostream &os, const matrix &rhs);
};

//-----------------------------------------------------------------------------

matrix::matrix()
{
    row = 0;
    col = 0;
    size = row * col;
    mat = nullptr;
}
matrix::matrix(int rows)
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
matrix::matrix(int rows, int cols, Elem val)
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
matrix::matrix(int rows, int cols, Elem *arr)
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
matrix::matrix(int rows, int cols, Elem **arr)
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
bool matrix::rerange(int rows, int cols)
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
void matrix::setElem(int rows, int cols, Elem val)
{
    mat[(rows - 1) * col + (cols - 1)] = val;
}
Elem matrix::getElem(int rows, int cols) const
{
    return mat[rows * col + cols];
}
Elem *matrix::operator[](int rows)
{
    return &mat[rows * col];
}
matrix matrix::T()
{
    matrix tmp(col, row);
    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
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
        matrix tmp(lhs.row, rhs.col);
        for (int i = 0; i < lhs.row; ++i)
        {
            for (int j = 0; j < rhs.col; ++j)
            {
                Elem sum = 0;
                for (int k = 0; k < lhs.col; ++k)
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
std::ostream &operator<<(std::ostream &os, const matrix &rhs)
{
    if (rhs.mat != nullptr)
    {
        for (int i = 0; i < rhs.row; ++i)
        {
            os << rhs.getElem(i, 0);
            for (int j = 1; j < rhs.col; ++j)
            {
                os << ' ' << rhs.getElem(i, j);
            }
            os << std::endl;
        }
    }
    return os;
}