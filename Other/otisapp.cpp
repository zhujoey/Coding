#include <iostream>
#include <cmath>
#include <algorithm>

bool prime(long long n)
{
    if (n % 2 == 0 && n != 2 || n % 3 == 0 && n != 3)
    {
        return false;
    }
    for (long long i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long long sum, digit, ans = 0, temp;
    bool valid;
    for (long long q = 2; q < 2146; ++q)
    {
        if (!prime(q))
        {
            continue;
        }
        for (long long p = 2; p < 99381; ++p)
        {
            if (!prime(p))
            {
                continue;
            }
            digit = 0;
            long long digits[10];
            sum = q * q * q + p * p;
            temp = sum;
            valid = true;
            while (sum > 0 && digit < 10)
            {
                digits[digit] = sum % 10;
                sum /= 10;
                ++digit;
            }
            if (sum > 0 || digit < 10)
            {
                continue;
            }
            std::sort(digits, digits + 10);
            for (int i = 0; i < 10; ++i)
            {
                if (digits[i] != i)
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                ++ans;
            }
        }
    }
    std::cout << ans;
    return 0;
}