/*
分解质因数: n = p1^a1 * p2^a2 * p3^a3 * .... * pk^ak;
factorSum(n)=(p1^0 + p1^1 + p1^2 + ... + p1^a1) * (p2^0 + p2^1 + p2^2 + ... + p2^a2) * ... * (pk^0 + pk^1 + pk^2 + ... + pk^ak);
*/

long long factorSum(long long n)
{
    long long res = 1;
    for (long long i = 2; i * i <= n; i++)
    {
        long long cnt = 0;
        while (n % i == 0)
        {
            ++cnt;
            n /= i;
        }
        res *= (quickPower(i, cnt + 1) - 1LL) / (i - 1LL); //quickPower.cpp
    }
    if (n > 1)
    {
        res *= n + 1;
    }
    return res;
}