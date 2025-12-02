#include <iostream>
#include <string>

int dfs(std::string &s, int l, int r, char c)
{
    int mid = 0, leftcost = 0, rightcost = 0, costleft = 0, costright = 0, result = 0;

    if (l == r)
    {
        if (s[l] == c)
        {
            result = 0;
        }
        else
        {
            result = 1;
        }
        return result;
    }

    mid = (l + r) / 2;

    for (int i = l; i <= mid; ++i)
    {
        if (s[i] != c)
        {
            leftcost++;
        }
    }

    for (int i = mid + 1; i <= r; ++i)
    {
        if (s[i] != c)
        {
            rightcost++;
        }
    }

    costleft = leftcost + dfs(s, mid + 1, r, c + 1);
    costright = rightcost + dfs(s, l, mid, c + 1);

    if (costleft < costright)
    {
        result = costleft;
    }
    else
    {
        result = costright;
    }

    return result;
}

int main()
{
    int t = 0, n = 0, result = 0;
    std::string s = "";

    std::cin >> t;

    while (t--)
    {
        std::cin >> n >> s;
        result = dfs(s, 0, n - 1, 'a');
        std::cout << result << '\n';
    }

    return 0;
}1