#include <iostream>
#include <algorithm>
 
int main()
{
    int t, n, s[200000], first, firstIndex, second;
    std::cin >> t;
    for (int i = 0; i < t; ++i)
    {
        std::cin >> n;
        
        for (int i = 0; i < n; ++i)
        {
            std::cin >> s[i];
        }
        if (n == 2)
        {
            first = std::max(s[0], s[1]);
            second = std::min(s[0], s[1]);
            if (s[0] > s[1])
            {
                firstIndex = 0;
            }
            else
            {
                firstIndex = 1;
            }
        }
        else
        {
            first = 0;
            second = 0;
            for (int i = 0; i < n; ++i)
            {
                if (s[i] > first)
                {
                    firstIndex = i;
                    first = s[i];
                }
            }
            for (int i = 0; i < n; ++i)
            {
                if (i != firstIndex)
                {
                    second = std::max(s[i], second);
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (firstIndex != i)
            {
                std::cout << s[i] -  first << " ";
            }
            else
            {
                std::cout << s[i] - second << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}