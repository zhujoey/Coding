#include <iostream>

int main() 
{
    long long t, n, l, r, o, ms, h[200005], p[200005], m[2];
    bool hs[200005];
    
    std::cin >> t;
    
    while (t--) 
    {
        std::cin >> n;
        
        for (long long i = 0; i <= n; ++i)
        {
            hs[i] = false;
        }
        
        o = 0;
        ms = 0;

        for (long long i = 0; i < n - 1; ++i) 
        {
            std::cin >> h[i];
            hs[h[i]] = true;
            if (h[i] == 1)
            {
                o++;
            }
        }

        for (long long i = 1; i <= n; ++i) 
        {
            if (!hs[i]) 
            {
                m[ms] = i;
                ms++;
            }
        }

        if (ms > 2 || h[n - 2] != 1 || (ms == 2 && o != 2)) 
        {
            std::cout << "-1\n";
            continue;
        }

        if (ms == 1) 
        {
            p[0] = 1;
            p[n - 1] = m[0];
        } 
        else 
        {
            p[0] = m[0];
            p[n - 1] = m[1];
        }

        l = 0;
        r = n - 1;
        for (long long i = 0; i < n - 1; ++i) 
        {
            if (p[l] > p[r]) 
            {
                p[++l] = h[i];
            }
            else 
            {
                p[--r] = h[i];
            }
        }

        for (long long i = 0; i < n; ++i) 
        {
            if (i) 
            {
                std::cout << " ";
            }
            std::cout << p[i];
        }
        std::cout << "\n";
    }
    return 0;
}