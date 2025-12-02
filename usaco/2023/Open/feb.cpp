#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

int main()
{
    long long n = 0, edgef = 0, least = 0, most = 0, increment = 0, a = 0, b = 0;
    std::vector<long long> spos, ans;

    std::string s;
    std::cin >> n >> s;

    if (std::count(s.begin(), s.end(), 'F') == n)
    {
        s[0] = 'E';
    }

    for (int i = 0; i < n; ++i)
    {
        if (s[i] != 'F')
        {
            spos.push_back(i);
        }
    }

    if (spos.size() == 0)
    {
        std::cout << 0 << '\n';
        return 0;
    }

    edgef = spos[0] + (n - 1 - spos[spos.size() - 1]);

    for (int i = 0; i + 1 < spos.size(); ++i)
    {
        a = spos[i];
        b = spos[i + 1];
        least += ((b - a) % 2) ^ (s[a] != s[b]);
        most += (b - a) - (s[a] != s[b]);
    }

    if (edgef == 0)
    {
        increment = 2;
    }
    else
    {
        increment = 1;
    }

    for (int i = least; i <= edgef + most; i += increment)
    {
        ans.push_back(i);
    }

    std::cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i)
    {
        std::cout << ans[i] << '\n';
    }

    return 0;
}