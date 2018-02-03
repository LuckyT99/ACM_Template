/*
mod 是质数:
inv[i] = (mod - mod / i) * inv[mod % i] % mod;
*/

long long inv[SIZE + 3];

void initInv(long long mod)
{
    inv[1] = 1;
    for (int i = 2; i < mod; ++i)
    {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
}