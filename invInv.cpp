/*
mod 是质数:
inv(divisor) = (mod - mod / divisor) * inv(mod % divisor) % mod;
*/

long long inv(long long divisor, long long mod) //divisor < mod
{
    return divisor == 1 ? 1 : (mod - mod / divisor) * inv(mod % divisor, mod) % mod;
}