/*
从筛法求出的质数中导入质数表;
*/

long long primes[SIZE_PRIME + 3], primeNumber = 0;

void initPrimes(long long n)
{
    initNotPrime(n); //initNotPrime.cpp
    primeNumber = 0;
    for (long long i = 0; i <= n; ++i)
    {
        if (!notPrime[i])
        {
            primes[primeNumber] = i;
            ++primeNumber;
        }
    }
    return;
}