/*
埃拉托色尼(Eratosthenes)筛法判断质数;
*/

bool notPrime[SIZE + 3];

void initNotPrime(long long n)
{
    notPrime[0] = true;
    notPrime[1] = true;
    for (long long i = 2; i * i <= n; ++i)
    {
        if (!notPrime[i])
        {
            for (long long j = i << 1; j <= n; j += i)
            {
                notPrime[j] = true;
            }
        }
    }
}