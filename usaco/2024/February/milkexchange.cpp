#include <iostream>
#include <numeric>
#include <string>
 
int main()
{
    long long n, m, a[200000], ans, sum, j;
    bool l[200000]{}, r[200000]{};
    std::string s;
    std::cin >> n >> m >> s;
    
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
	
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R' && s[(i + 1) % n] == 'L')
        {
            l[i] = true;
            r[(i + 1) % n] = true;
        }
    }
        
    ans = std::accumulate(a, a + n, 0ll);
    
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        if (l[i])
        {
            j = (i - 1 + n) % n;
            while (s[j] == 'R')
            {
                sum += a[j];
                --j;
                if (j < 0)
                {
                    j += n;
                }
            }
        }
        if (r[i])
        {
            j = (i + 1) % n;
            while (s[j] == 'L')
            {
                sum += a[j];
                ++j;
                if (j >= n)
                {
                    j -= n;
                }
            }
        }
        
        ans -= std::min(sum, m);
    }
    std::cout << ans << "\n";
    return 0;
}