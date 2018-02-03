/*
欧拉(Euler)线性筛法求质数及质数个数并导出质数表;
*/

long long primes[SIZE_PRIME + 3], primeNumber = 0;
bool notPrime[SIZE + 3];

void initEulerPrimes(long long n)
{
    notPrime[0] = true;
    notPrime[1] = true;
    for (int i = 2; i < n; ++i)
    {
        if (!notPrime[i])
        {
            primes[primeNumber] = i;
            ++primeNumber;
        }
        for (int j = 0; j < primeNumber && i * primes[j] < n; j++)
        {
            notPrime[i * primes[j]] = true;
            if (i % primes[j] == 0)
            {
                break;
            }
        }
    }
}