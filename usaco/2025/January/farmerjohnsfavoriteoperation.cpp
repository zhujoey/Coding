#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    int t, tc, n, m, i;
    long long ans;
    std::vector<int> a;
    std::vector<long long> cum;
    
    if (std::cin >> t)
    {
        for (tc = 0; tc < t; ++tc)
        {
            std::cin >> n >> m;
            
            a.resize(n);
            for (i = 0; i < n; ++i)
            {
                std::cin >> a[i];
                a[i] = a[i] % m;
            }
            
            std::sort(a.begin(), a.end());
            
            for (i = 0; i < n; ++i)
            {
                a.push_back(a[i] + m);
            }
            
            cum.resize(2 * n + 1, 0);
            for (i = 0; i < 2 * n; ++i)
            {
                cum[i + 1] = cum[i] + a[i];
            }
            
            ans = -1;
            for (i = 0; i < n; ++i)
            {
                long long current = cum[i + n] - cum[i + n - n / 2] - cum[i + n / 2] + cum[i];
                if (ans == -1 || current < ans)
                {
                    ans = current;
                }
            }
            
            std::cout << ans << "\n";
            
            a.clear();
            cum.clear();
        }
    }
    
    return 0;
}