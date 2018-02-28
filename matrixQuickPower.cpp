#include "matrix.hpp"

matrix matrixQuickPower(matrix bottomNumber, long long index)
{
    if (bottomNumber.getRow() != bottomNumber.getColumn())
    {
        matrix res;
        return res;
    }
    matrix res(bottomNumber.getRow());
    while (index)
    {
        if (index & 1)
        {
            res *= bottomNumber;
        }
        bottomNumber *= bottomNumber;
        index >>= 1;
    }
    return res;
}