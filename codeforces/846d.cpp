#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>

int main()
{
    int n, m, k, q, sum[505][505];
    std::array<int, 3> broken[250005], subset[250005];
    std::cin >> n >> m >> k >> q;

    for (int i = 0; i < q; ++i)
    {
        std::cin >> broken[i][0] >> broken[i][1] >> broken[i][2];
    }

    std::sort(broken, broken + q, [](const std::array<int, 3> &a, const std::array<int, 3> &b)
    {
        return a[2] < b[2];
    });

    int left = 0, right = q - 1, answer = -1, mid, currentTime;

    while (left <= right)
    {
        mid = (left + right) / 2;
        currentTime = broken[mid][2];

        std::memset(sum, 0, sizeof(sum));
        for (int i = 0; i <= mid; ++i)
        {
            int row = broken[i][0];
            int col = broken[i][1];
            sum[row][col] = 1;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }

        bool found = false;
        for (int i = k; i <= n && !found; ++i)
        {
            for (int j = k; j <= m; ++j)
            {
                int total = sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k];

                if (total == k * k)
                {
                    answer = currentTime;
                    right = mid - 1;
                    found = true;
                    break;
                }
            }
        }

        if (!found)
        {
            left = mid + 1;
        }
    }

    std::cout << answer << std::endl;
    return 0;
}