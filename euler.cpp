/*
欧拉函数求小于 n 的数中与 n 互质的数的数目;
*/

long long euler(long long n)
{
    long long res = n;
    for (long long i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            res -= res / i;
        }
    }
    if (n > 1)
    {
        res -= res / n;
    }
    return res;
}