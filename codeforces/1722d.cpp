#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    long long t, n, val;
    char directions[200001];
    int opposite[200001];
    std::cin >> t;
    while (t--)
    {
        val = 0;
        std::cin >> n >> directions;
        for (int i = 0; i < n; ++i)
        {
            if (directions[i] == 'R')
            {
                val += n - i - 1;
            }
            else
            {
                val += i;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (directions[i] == 'L')
            {
                opposite[i] = n - 2 * i - 1;
            }
            else
            {
                opposite[i] = 2 * i - n + 1;
            }
        }
        std::sort(opposite, opposite + n, std::greater<int>());
        for (int i = 0; i < n; ++i)
        {
            if (opposite[i] > 0)
            {
                val += opposite[i];
            }
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
    return 0;
}