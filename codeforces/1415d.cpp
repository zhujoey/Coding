#include <iostream>

int main()
{
    int n, a[100005], res = 100005, leftxor = 0, rightxor = 0, ops = 0;

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    if (n >= 60)
    {
        std::cout << 1 << std::endl;
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        leftxor = 0;

        for (int j = i; j >= 0; --j)
        {
            leftxor ^= a[j];
            rightxor = 0;

            for (int k = i + 1; k < n; ++k)
            {
                rightxor ^= a[k];

                if (leftxor > rightxor)
                {
                    ops = k - j - 1;
                    if (ops < res)
                    {
                        res = ops;
                    }
                }
            }
        }
    }

    if (res == 100005)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << res << std::endl;
    }

    return 0;
}