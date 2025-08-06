
#include <iostream>
#include <algorithm>

int main()
{
    long long n, m, cows[200000], candy, start, temp;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> cows[i];
    }
    
    for (int i = 0; i < m; ++i)
    {
        std::cin >> start;
        candy = start;
        for (int i = 0; i < n; ++i)
        {
            if (cows[i] > start - candy)
            {
                temp = cows[i];
                cows[i] += std::min(cows[i] - start + candy, candy);
                candy = start - temp;
            }
            if (candy <= 0)
            {
                break;
            }
        }
    }
    
    for (int i = 0; i < n; ++i)
    {
        std::cout << cows[i] << "\n";
    }
    
    return 0;
}