/*
求所有数的欧拉(Euler)函数同时求质数及质数个数并导出质数表;
*/

long long primes[SIZE_PRIME + 3], primeNumber = 0, phi[SIZE + 3];
bool notPrime[SIZE + 3];

void initEulerPrimes(long long n)
{
    notPrime[0] = true;
    phi[0] = 0;
    notPrime[1] = true;
    phi[1] = 0;
    for (int i = 2; i < n; ++i)
    {
        if (!notPrime[i])
        {
            primes[primeNumber] = i;
            ++primeNumber;
            phi[i] = i - 1;
        }
        for (int j = 0; j < primeNumber && i * primes[j] <= n; j++)
        {
            notPrime[i * primes[j]] = true;
            if (i % primes[j] == 0)
            {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            else
            {
                phi[i * primes[j]] = phi[i] * (primes[j] - 1);
            }
        }
    }
}