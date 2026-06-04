#include <iostream>

long long power(long long base, long long exp, long long mod)
{
    long long res = 1;
    base %= mod;
    if (base < 0)
    {
        base += mod;
    }
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main()
{
    long long n, m, l, r, mod, k, ans, termone, termtwo, rto, lto, o, e, diff, inv;
    std::cin >> n >> m >> l >> r;
    mod = 998244353;
    k = r - l + 1;

    if ((n % 2 != 0) && (m % 2 != 0))
    {
        ans = power(k, n, mod);
        ans = power(ans, m, mod);
        std::cout << ans << "\n";
    }
    else
    {
        rto = (r + 1) / 2;
        lto = l / 2;
        o = rto - lto;
        e = k - o;
        diff = e - o;

        termone = power(k, n, mod);
        termone = power(termone, m, mod);

        termtwo = power(diff, n, mod);
        termtwo = power(termtwo, m, mod);

        ans = (termone + termtwo) % mod;
        inv = (mod + 1) / 2;
        ans = (ans * inv) % mod;

        std::cout << ans << "\n";
    }

    return 0;
}