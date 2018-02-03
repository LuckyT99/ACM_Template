/*
bottomNumber^index = (bottomNumber^(index / 2))^2 * (index & 1 ? bottomNumber : 1);
*/

long long quickPower(long long bottomNumber, long long index)
{
    long long res = 1;
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