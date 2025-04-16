#include <fstream>
#include <algorithm>

int n, temp, res = 0, current, rems[50001], indices[7] = {-1, -1, -1, -1, -1, -1, -1}, revis[7] = {-1, -1, -1, -1, -1, -1, -1};

int main()
{
    std::ifstream nums("div7.in");
    std::ofstream ans("div7.out");

    nums >> n;
    nums >> temp;
    rems[0] = temp % 7;

    for (int i = 1; i < n; ++i)
    {
        nums >> temp;
        rems[i] = (temp + rems[i - 1]) % 7;
    }

    for (int i = 0; i < n; ++i)
    {
        if (indices[rems[i]] == -1)
        {
            indices[rems[i]] = i;
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        if (revis[rems[i]] == -1)
        {
            revis[rems[i]] = i;
        }
    }

    for (int i = 0; i < 7; ++i)
    {
        res = std::max(res, revis[i] - indices[i]);
    }

    ans << res;

    nums.close();
    ans.close();
    return 0;
}