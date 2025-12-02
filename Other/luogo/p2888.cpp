#include <iostream>
#include <algorithm>

int main()
{
    long long n, m, t, height[300][300], s, e;
    std::cin >> n >> m >> t;
    for (int i = 0; i < 300; ++i)
    {
        for (int j = 0; j < 300; ++j)
        {
            height[i][j] = 1000001;
        }
    }
    while (m--)
    {
        std::cin >> s >> e;
        std::cin >> height[s - 1][e - 1];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                height[j][k] = std::min(height[j][k], std::max(height[j][i], height[i][k]));
            }
        }
    }
    while (t--)
    {
        std::cin >> s >> e;
        if (height[s - 1][e - 1] == 1000001)
        {
            std::cout << "-1\n";
        }
        else
        {
            std::cout << height[s - 1][e - 1] << "\n";
        }
    }
    return 0;
}