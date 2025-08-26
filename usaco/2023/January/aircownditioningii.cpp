#include <iostream>
#include <algorithm>
#include <climits>

int main()
{
    long long n = 0, m = 0, ret = 0, cost = 0, used = 0, i = 0, x = 0;
    long long regions[100][3] = {0}, acs[10][4] = {0}, cool[101] = {0};
    bool valid = true;

    std::cin >> n >> m;

    for (i = 0; i < n; ++i)
    {
        std::cin >> regions[i][0] >> regions[i][1] >> regions[i][2];
    }

    for (i = 0; i < m; ++i)
    {
        std::cin >> acs[i][0] >> acs[i][1] >> acs[i][2] >> acs[i][3];
    }

    for (i = 0; i < m; ++i)
    {
        ret += acs[i][3];
    }

    for (used = 0; used < (1LL << m); ++used)
    {
        std::fill(cool, cool + 101, 0);
        cost = 0;
        valid = true;

        for (i = 0; i < m; ++i)
        {
            if (used & (1LL << i))
            {
                cost += acs[i][3];
                for (x = acs[i][0]; x <= acs[i][1]; ++x)
                {
                    cool[x] += acs[i][2];
                }
            }
        }

        for (i = 0; i < n; ++i)
        {
            for (x = regions[i][0]; x <= regions[i][1]; ++x)
            {
                if (cool[x] < regions[i][2])
                {
                    valid = false;
                    break;
                }
            }
            if (!valid)
            {
                break;
            }
        }

        if (valid)
        {
            ret = std::min(ret, cost);
        }
    }

    std::cout << ret << std::endl;
    return 0;
}