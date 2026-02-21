#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, temp, pre = 0;
    std::vector<int> a, b;
    std::cin >> n;
    int ans[n + 1] = {};
    for (int i = 0; i < n; ++i)
    {
        std::cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> temp;
        b.push_back(temp);
        if (temp == a[i])
        {
            ++pre;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        temp = pre;
        for (int l = i, r = i; l >= 0 && r < n; --l, ++r)
        {
            if (a[l] == b[r])
            {
                ++temp;
            }
            if (a[r] == b[l])
            {
                ++temp;
            }
            if (a[l] == b[l])
            {
                --temp;
            }
            if (a[r] == b[r])
            {
                --temp;
            }
            ++ans[temp];
        }
        temp = pre;
        for (int l = i, r = i + 1; l >= 0 && r < n; --l, ++r)
        {
            if (a[l] == b[r])
            {
                ++temp;
            }
            if (a[r] == b[l])
            {
                ++temp;
            }
            if (a[l] == b[l])
            {
                --temp;
            }
            if (a[r] == b[r])
            {
                --temp;
            }
            ++ans[temp];
        }
        temp = pre;
    }
    for (int i = 0; i <= n; ++i)
    {
        std::cout << ans[i] << "\n";
    }
    return 0;
}