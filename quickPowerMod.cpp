/*
bottomNumber^index % mod = (bottomNumber^(index / 2) % mod)^2 % mod * (index & 1 ? bottomNumber : 1) % mod;
*/

long long quickPowerMod(long long bottomNumber, long long index, long long mod)
{
    long long res = 1;
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