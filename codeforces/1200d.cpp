#include <iostream>
#include <utility>
#include <algorithm>

int main()
{
    int n, k, base = 0,  best = 0, len = 0, top = 0, bottom = 0, left = 0, right = 0, diff[2005][2005];
    char grid[2000][2000];
    std::pair<int,int> rowend[2000], colend[2000];
    std::cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        rowend[i] = {n, -1};
        colend[i] = {n, -1};
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 'B')
            {
                if (j < rowend[i].first)
                {
                    rowend[i].first = j;
                }
                if (j > rowend[i].second)
                {
                    rowend[i].second = j;
                }
            }
        }
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (grid[i][j] == 'B')
            {
                if (i < colend[j].first)
                {
                    colend[j].first = i;
                }
                if (i > colend[j].second)
                {
                    colend[j].second = i;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (rowend[i].second == -1)
        {
            base++;
        }
        if (colend[i].second == -1)
        {
            base++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (rowend[i].second == -1)
        {
            continue;
        }
        len = rowend[i].second - rowend[i].first + 1;
        if (len > k)
        {
            continue;
        }
        top = std::max(0, i - k + 1);
        bottom = i;
        left = std::max(0, rowend[i].second - k + 1);
        right = rowend[i].first;
        diff[top][left]++;
        diff[top][right+1]--;
        diff[bottom+1][left]--;
        diff[bottom+1][right+1]++;
    }

    for (int j = 0; j < n; j++)
    {
        if (colend[j].second == -1)
        {
            continue;
        }
        len = colend[j].second - colend[j].first + 1;
        if (len > k)
        {
            continue;
        }
        left = std::max(0, j - k + 1);
        right = j;
        top = std::max(0, colend[j].second - k + 1);
        bottom = colend[j].first;
        diff[top][left]++;
        diff[top][right+1]--;
        diff[bottom+1][left]--;
        diff[bottom+1][right+1]++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0)
            {
                diff[i][j] += diff[i-1][j];
            }
            if (j > 0)
            {
                diff[i][j] += diff[i][j-1];
            }
            if (i > 0 && j > 0)
            {
                diff[i][j] -= diff[i-1][j-1];
            }
            if (diff[i][j] > best)
            {
                best = diff[i][j];
            }
        }
    }

    std::cout << base + best << "\n";
    return 0;
}