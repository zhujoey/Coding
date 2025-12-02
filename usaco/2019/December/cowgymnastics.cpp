#include <fstream>
#include <vector>

int main()
{
    std::ifstream fin("gymnastics.in");
    std::ofstream fout("gymnastics.out");
    int n, k, temp, ans = 0;
    bool found, valid;
    fin >> k >> n;
    std::vector<int> rank;
    std::vector<std::vector<int>> all;
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            fin >> temp;
            rank.push_back(temp);
        }
        all.push_back(rank);
        rank.clear();
    }
    for (int a = 1; a <= n; ++a)
    {
        for (int b = 1; b <= n; ++b)
        {
            if (a == b)
            {
                continue;
            }
            for (int i = 0; i < k; ++i)
            {
                found = false;
                valid = false;
                for (int j = 0; j < n; ++j)
                {
                    if (all[i][j] == a)
                    {
                        valid = true;
                        break;
                    }
                    else if (all[i][j] == b)
                    {
                        break;
                    }
                }
                if (!valid)
                {
                    break;
                }
            }
            if (valid)
            {
                ++ans;
            }
        }
    }
    fout << ans;
    fin.close();
    fout.close();
    return 0;
}