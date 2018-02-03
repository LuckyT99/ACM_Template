/*
mod 是质数且 divisor 与 mod 互质:
inv(divisor) ≡ divisor^(mod - 2) % mod;
*/

long long inv(long long divisor, long long mod)
{
    return quickPowerMod(divisor, mod - 2, mod); //quickPowerMod.cpp
}