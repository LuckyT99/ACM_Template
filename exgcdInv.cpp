/*
divisor 与 mod 互质:
exgcd(divisor, mod, x, y);
inv(divisor) ≡ x % mod;
*/

long long inv(long long divisor, long long mod)
{
    long long x, y, gcd = exgcd(divisor, mod, x, y); //exgcd.cpp
    return gcd == 1 ? (x % mod + mod) % mod : -1;    //如果 divisor 与 mod 不互质，返回 -1
}