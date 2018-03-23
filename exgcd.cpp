/*
a * x + b * y == gcd(a, b);
*/

long long exgcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long res = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return res;
}
