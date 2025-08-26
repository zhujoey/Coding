#include <iostream>
#include <string>

int main()
{
    long long n, e[100000], firstg, firsth, lastg, lasth, ans = 0;
    std::string s;
    std::cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        std::cin >> e[i];
        e[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'G')
        {
            firstg = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'G')
        {
            lastg = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'H')
        {
            firsth = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'H')
        {
            lasth = i;
            break;
        }
    }
    if (e[firstg] >= lastg)
    {
        for (int i = 0; i < firstg; i++)
        {
            if (i == firsth)
            {
                continue;
            }
            if (s[i] == 'H' && e[i] >= firstg)
            {
                ans++;
            }
        }
    }
    if (e[firsth] >= lasth)
    {
        for (int i = 0; i < firsth; i++)
        {
            if (i == firstg)
            {
                continue;
            }
            if (s[i] == 'G' && e[i] >= firsth)
            {
                ans++;
            }
        }
    }
    if ((e[firstg] >= lastg || (firstg <= firsth && e[firstg] >= firsth)) && (e[firsth] >= lasth || (firsth <= firstg && e[firsth] >= firstg)))
    {
        ans++;
    }
    std::cout << ans << '\n';
    return 0;
}