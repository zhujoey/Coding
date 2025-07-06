#include <iostream>
#include <string>

int main()
{
    std::string t = "", p = "";
    std::cin >> t >> p;

    int n = t.size();
    int left = 0, right = n, res = 0, mid = 0, ti = 0, pi = 0;
    int order[200000] = {0};
    bool rem[200000] = {false};

    for (int i = 0; i < n; i++)
    {
        std::cin >> order[i];
    }

    while (left <= right)
    {
        mid = (left + right) / 2;

        for (int i = 0; i < n; i++)
        {
            rem[i] = false;
        }

        for (int i = 0; i < mid; i++)
        {
            rem[order[i] - 1] = true;
        }

        ti = 0;
        pi = 0;

        while (ti < n && pi < p.size())
        {
            if (!rem[ti] && t[ti] == p[pi])
            {
                pi++;
            }
            ti++;
        }

        if (pi == p.size())
        {
            res = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    std::cout << res << "\n";
    return 0;
}