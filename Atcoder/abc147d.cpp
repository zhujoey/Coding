#include <iostream>
#include <vector>
#include <array>

int main()
{
    const long long mod = 1000000007ll;

    long long n, num, pos, ones, zeros, ans = 0, temp;
    std::cin >> n;

    std::vector<std::array<bool, 60>> binary(n);
    for (int j = 0; j < n; ++j)
    {
        binary[j].fill(false);
    }

    for (int j = 0; j < n; ++j)
    {
        std::cin >> num;
        pos = 59;
        while (num > 0 && pos >= 0)
        {
            binary[j][pos] = (num % 2);
            num /= 2;
            --pos;
        }
    }

    long long pow2[60];
    pow2[0] = 1;
    for (int i = 1; i < 60; ++i)
    {
        pow2[i] = (pow2[i - 1] * 2) % mod;
    }

    for (int i = 59; i >= 0; --i)
    {
        ones = 0;
        zeros = 0;

        for (int j = 0; j < n; ++j)
        {
            if (binary[j][i])
            {
                ++ones;
            }
            else
            {
                ++zeros;
            }
        }

        temp = (ones % mod) * (zeros % mod) % mod;
        temp = temp * pow2[59 - i] % mod;
        ans += temp;
        ans %= mod;
    }

    std::cout << ans;
    return 0;
}