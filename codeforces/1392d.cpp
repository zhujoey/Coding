#include <iostream>
#include <vector>

int main()
{
    int t, n, ans;
    std::cin >> t;
    std::vector<std::vector<char>> s;
    std::vector<char> group;
    char prev = 0, temp;
    while (t--)
    {
        ans = 0;
        std::cin >> n;
        prev = 0;
        s.clear();
        group.clear();

        for (int i = 0; i < n; ++i)
        {
            std::cin >> temp;
            if (i == 0)
            {
                group.push_back(temp);
                prev = temp;
            }
            else if (temp == prev)
            {
                group.push_back(temp);
            }
            else
            {
                s.push_back(group);
                group.clear();
                group.push_back(temp);
                prev = temp;
            }
        }
        if (!group.empty())
        {
            s.push_back(group);
        }

        if (s.size() == 1)
        {
            std::cout << (n + 2) / 3 << "\n";
            continue;
        }

        if (s.front()[0] == s.back()[0])
        {
            s.front().insert(s.front().begin(), s.back().begin(), s.back().end());
            s.pop_back();
        }

        for (std::vector<char> i : s)
        {
            ans += i.size() / 3;
        }

        std::cout << ans << "\n";
    }
    return 0;
}