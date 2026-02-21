#include <iostream>
#include <vector>
#include <string>

int main()
{
    int t, k, n, indices[3], posa, posb;
    bool two;
    std::string s, a, b, cow;
    std::vector<int> ans;
    std::cin >> t >> k;

    while (t--)
    {
        std::cin >> n >> s;

        if (n % 2 == 1)
        {
            std::cout << -1 << "\n";
            continue;
        }

        two = false;
        ans.assign(3 * n, 0);

        for (int i = 0; i < n / 2; ++i)
        {
            a = s.substr(3 * i, 3);
            b = s.substr((n * 3 / 2) + 3 * i, 3);
            cow = "COW";

            for (char c : cow)
            {
                posa = -1;
                posb = -1;
                for (int j = 0; j < 3; ++j)
                {
                    if (a[j] == c)
                    {
                        posa = j;
                    }
                    if (b[j] == c)
                    {
                        posb = j;
                    }
                }
                indices[posa] = posb;
            }

            if (indices[0] == 2 && indices[1] == 0 && indices[2] == 1)
            {
                two = true;
                ans[3 * i] = 2;
                ans[(n * 3 / 2) + 3 * i + 2] = 2;
                ans[3 * i + 1] = 1;
                ans[(n * 3 / 2) + 3 * i + 0] = 1;
                ans[3 * i + 2] = 1;
                ans[(n * 3 / 2) + 3 * i + 1] = 1;
            }
            else if (indices[0] == 1 && indices[1] == 2 && indices[2] == 0)
            {
                two = true;
                ans[3 * i] = 1;
                ans[(n * 3 / 2) + 3 * i + 1] = 1;
                ans[3 * i + 1] = 1;
                ans[(n * 3 / 2) + 3 * i + 2] = 1;
                ans[3 * i + 2] = 2;
                ans[(n * 3 / 2) + 3 * i + 0] = 2;
            }
            else
            {
                ans[3 * i] = 1;
                ans[(n * 3 / 2) + 3 * i] = 1;
                ans[3 * i + 1] = 1;
                ans[(n * 3 / 2) + 3 * i + 1] = 1;
                ans[3 * i + 2] = 1;
                ans[(n * 3 / 2) + 3 * i + 2] = 1;
            }
        }

        if (two)
        {
            std::cout << 2 << "\n";
        }
        else
        {
            std::cout << 1 << "\n";
        }

        for (int i = 0; i < 3 * n; ++i)
        {
            std::cout << ans[i];
            if (i < 3 * n - 1)
            {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}