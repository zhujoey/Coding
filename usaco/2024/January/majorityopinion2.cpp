#include <iostream>
#include <set>

int main()
{
    int t, n, prev, prevprev, current;
    std::set<int> ans;
    std::cin >> t;
    while (t--)
    {
        ans.clear();
        std::cin >> n >> prevprev >> prev;
        if (prev == prevprev)
        {
            ans.insert(prev);
        }
        for (int i = 2; i < n; ++i)
        {
            std::cin >> current;
            if (current == prevprev)
            {
                ans.insert(current);
            }
            if (current == prev)
            {
                ans.insert(current);
            }
            prevprev = prev;
            prev = current;
        }
        if (ans.empty())
        {
            std::cout << -1 << "\n";
            continue;
        }
        bool first = true;
        for (long long i : ans)
        {
            if (!first)
            {
                std::cout << " ";
            }
            std::cout << i;
            first = false;
        }
        std::cout << "\n";
    }
    return 0;
}