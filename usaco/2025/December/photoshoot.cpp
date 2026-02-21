#include <iostream>
#include <algorithm>

int main()
{
    int n, k, q, r, c, v, ans = 0, change;
    std::cin >> n >> k >> q;
    int field[n - k + 1][n - k + 1] = {}, cow[n][n] = {};
    while (q--)
    {
        std::cin >> r >> c >> v;
        --r;
        --c;

        change = v - cow[r][c];
        cow[r][c] = v;

        for (int i = std::max(0, r - k + 1); i <= r && i <= n - k; ++i)
        {
            for (int j = std::max(0, c - k + 1); j <= c && j <= n - k; ++j)
            {
                field[i][j] += change;
                ans = std::max(ans, field[i][j]);
            }
        }

        std::cout << ans << "\n";
    }

    return 0;
}