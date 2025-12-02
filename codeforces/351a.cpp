#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>

int main()
{
    long long n, nonintcount = 0, lo = 0, hi = 0;
    double temp, frac = 0, sumfrac = 0, ans = 1000000000000000000.0;

    std::cin >> n;

    for (long long i = 0; i < 2 * n; i++)
    {
        std::cin >> temp;
        frac = temp - std::floor(temp);
        if (frac > 0.000000001)
        {
            sumfrac += frac;
            nonintcount++;
        }
    }

    lo = std::max(0LL, nonintcount - n);
    hi = std::min(n, nonintcount);

    for (long long i = lo; i <= hi; i++)
    {
        ans = std::min(ans, std::fabs(i - sumfrac));
    }

    std::cout << std::fixed << std::setprecision(3) << ans << "\n";
    return 0;
}