#include <iostream>
#include <vector>
#include <stack>

int main()
{
    int n, a;
    std::vector<int> ans;
    std::stack<int> threes, twos;
    std::cin >> n;
    int nextrow = 1;

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a;

        if (a == 1)
        {
            // consider twos before threes
            if (!twos.empty())
            {
                ans.push_back(twos.top());
                ans.push_back(i);
                twos.pop();
            }
            else if (!threes.empty())
            {
                ans.push_back(threes.top());
                ans.push_back(i);
                ans.push_back(nextrow);
                ans.push_back(i);
                ++nextrow;
                threes.pop();
            }
            else
            {
                ans.push_back(nextrow);
                ans.push_back(i);
                ++nextrow;
            }
        }
        else if (a == 2)
        {
            if (!threes.empty())
            {
                ans.push_back(threes.top());
                ans.push_back(i);
                ans.push_back(nextrow);
                ans.push_back(i);
                threes.pop();
                twos.push(nextrow);
                ++nextrow;
            }
            else
            {
                ans.push_back(nextrow);
                ans.push_back(i);
                twos.push(nextrow);
                ++nextrow;
            }
        }
        else if (a == 3)
        {
            if (!threes.empty())
            {
                ans.push_back(threes.top());
                ans.push_back(i);
                ans.push_back(nextrow);
                ans.push_back(i);
                threes.pop();
                threes.push(nextrow);
                ++nextrow;
            }
            else
            {
                ans.push_back(nextrow);
                ans.push_back(i);
                threes.push(nextrow);
                ++nextrow;
            }
        }

        if (nextrow > n + 1)
        {
            std::cout << "-1";
            return 0;
        }
    }

    if (!twos.empty() || !threes.empty())
    {
        std::cout << "-1";
        return 0;
    }

    std::cout << ans.size() / 2 << '\n';
    for (int i = 0; i < (int)ans.size(); i += 2)
    {
        std::cout << ans[i] << ' ' << ans[i + 1] << '\n';
    }

    return 0;
}