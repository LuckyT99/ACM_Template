#include "matrix.hpp"

matrix matrixQuickPowerMod(matrix bottomNumber, long long index, long long mod)
{
    if (bottomNumber.getRow() != bottomNumber.getColumn())
    {
        matrix res;
        return res;
    }
    matrix res(bottomNumber.getRow());
    bottomNumber %= mod;
    while (index)
    {
        if (index & 1)
        {
            res *= bottomNumber;
            res %= mod;
        }
        bottomNumber *= bottomNumber;
        bottomNumber %= mod;
        index >>= 1;
    }
    return res;
}