#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, a, b, ans, i, children, logchildren, pow;
    
    std::cin >> n;
    
    std::vector<int> d(n, 0);
    
    for (i = 0; i < n - 1; i++)
    {
        std::cin >> a >> b;
        a--;
        b--;
        d[a]++;
        d[b]++;
    }
    
    ans = n - 1;
    
    for (i = 0; i < n; i++)
    {
        if (d[i] > 1 || i == 0)
        {
            children = d[i];
            if (i != 0)
            {
                children--;
            }
            
            logchildren = 0;
            pow = 1;
            while (pow < children + 1)
            {
                logchildren++;
                pow *= 2;
            }
            ans += logchildren;
        }
    }
    
    std::cout << ans << '\n';
    return 0;
}