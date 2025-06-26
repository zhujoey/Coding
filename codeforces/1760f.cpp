#include <iostream>
#include <algorithm>
 
int main()
{
    int t;
    std::cin >> t;
 
    long long n, c, d, a[200000];
    int tc, i, left, right, mid, ans;
    long long s, cycles, rem, total, leftover, earnings;
 
    for (tc = 0; tc < t; ++tc)
    {
        std::cin >> n >> c >> d;
        for (i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }
 
        std::sort(a, a + n, std::greater<long long>());
 
        s = 0;
        for (i = 0; i < std::min((long long)d, n); ++i)
        {
            s += a[i];
        }
 
        if (s >= c)
        {
            std::cout << "Infinity\n";
            continue;
        }
 
        if (a[0] * d < c)
        {
            std::cout << "Impossible\n";
            continue;
        }
 
        left = 0;
        right = d;
        ans = -1;
 
        while (left <= right)
        {
            mid = (left + right) / 2;
            cycles = d / (mid + 1);
            rem = d % (mid + 1);
            total = 0;
            leftover = 0;
 
            for (i = 0; i < std::min(mid + 1, (int)n); ++i)
            {
                total += a[i];
            }
 
            for (i = 0; i < std::min((int)rem, (int)n); ++i)
            {
                leftover += a[i];
            }
 
            earnings = total * cycles + leftover;
 
            if (earnings >= c)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
 
        std::cout << ans << "\n";
    }
 
    return 0;
}