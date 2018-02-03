/*
求最大公约数;
*/

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}