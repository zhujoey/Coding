#include <iostream>
#include <cmath>
#include <unordered_map>
#include <utility>
 
bool prime(long long n)
{
    if (n <= 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (long long i = 5; i <= std::sqrt(n); i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}
 
std::pair<long long, long long> semiprime(long long n)
{
    if (prime(n))
    {
        return {1, 1};
    }
    if (n % 2 == 0)
    {
        if (prime(n / 2))
        {
            if (n / 2 == 2)
            {
                return {2, 1};
            }
            else
            {
                return {2, n / 2};
            }
        }
        else
        {
            return {1, 1};
        }
    }
    if (n % 3 == 0)
    {
        if (prime(n / 3))
        {
            if (n / 3 == 3)
            {
                return {3, 1};
            }
            else
            {
                return {3, n / 3};
            }
        }
        else
        {
            return {1, 1};
        }
    }
    for (long long i = 5; i <= std::sqrt(n); i += 6)
    {
        if (n % i == 0)
        {
            if (prime(i) && prime(n / i))
            {
                if (i == n / i)
                {
                    return {i, 1};
                }
                else
                {
                    return {i, n / i};
                }
            }
            else
            {
                return {1, 1};
            }
        }
        if (n % (i + 2) == 0)
        {
            if (prime(i + 2) && prime(n / (i + 2)))
            {
                if (i + 2 == n / (i + 2))
                {
                    return {i + 2, 1};
                }
                else
                {
                    return {i + 2, n / (i + 2)};
                }
            }
            else
            {
                return {1, 1};
            }
        }
    }
    return {1, 1};
}
 
int main()
{
    long long t, n, ans, numPrimes, temp;
    std::pair<long long, long long> temp1;
    std::unordered_map<long long, long long> primes;
    std::unordered_map<long long, std::pair<long long, std::pair<long long, long long>>> semiprimes;
    std::cin >> t;
    while (t--)
    {
        ans = 0;
        numPrimes = 0;
        std::cin >> n;
        primes.clear();
        semiprimes.clear();
        for (long long i = 0; i < n; ++i)
        {
            std::cin >> temp;
            temp1 = semiprime(temp);
            if (prime(temp))
            {
                ++primes[temp];
                ++numPrimes;
            }
            else if (temp1 != std::pair<long long, long long>{1, 1})
            {
                ++semiprimes[temp].first;
                semiprimes[temp].second = temp1;
            }
        }
        for (std::unordered_map<long long, long long>::iterator i = primes.begin(); i != primes.end(); ++i)
        {
            temp = i->second;
            ans += (numPrimes - temp) * temp;
        }
        ans /= 2;
        for (std::unordered_map<long long, std::pair<long long, std::pair<long long, long long>>>::iterator i = semiprimes.begin(); i != semiprimes.end(); ++i)
        {
            temp = i->second.first;
            ans += (primes[i->second.second.first] + primes[i->second.second.second]) * temp + temp * (temp + 1) / 2;
        }
        std::cout << ans << "\n";
    }
    return 0;
}