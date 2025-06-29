#include <iostream>
#include <string>
#include <cmath>

int main()
{
    int t, n, numleft, numright, left0, right1, have0, have1, res;
    double dist, min;
    std::string a;
    int zero[300000], one[300000];
    std::cin >> t;
    while (t > 0)
    {
        std::cin >> n >> a;
        zero[0] = 0;
        one[0] = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == '0')
            {
                zero[i + 1] = zero[i] + 1;
            }
            else
            {
                zero[i + 1] = zero[i];
            }
            if (a[i] == '1')
            {
                one[i + 1] = one[i] + 1;
            }
            else
            {
                one[i + 1] = one[i];
            }
        }
        res = -1;
        min = n + 1.0;
        for (int i = 0; i <= n; ++i)
        {
            numleft = i;
            numright = n - i;
            left0 = (numleft + 1) / 2;
            right1 = (numright + 1) / 2;
            have0 = zero[i];
            have1 = one[n] - one[i];
            dist = std::abs(i - n / 2.0);
            if (have0 >= left0 && have1 >= right1)
            {
                if (dist < min || (std::abs(dist - min) < 0.000000001 && (res == -1 || i < res)))
                {
                    res = i;
                    min = dist;
                }
            }
        }
        std::cout << res << '\n';
        --t;
    }
    return 0;
}