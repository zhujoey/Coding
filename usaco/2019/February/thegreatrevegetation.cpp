
#include <iostream>

int main()
{
    int n, m, a[151], b[151], g[101], type;
    bool valid;
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    { 
        std::cin >> a[i] >> b[i];
        if (a[i] > b[i])
        {
            std::swap(a[i], b[i]);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (type = 1; type <= 4; ++type)
        {
            valid = true;
            for (int j = 0; j < m; ++j)
            {
                if (b[j] == i && g[a[j]] == type)
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                break;
            }
        }
        g[i] = type;
        std::cout << type;
    }
    std::cout << "\n";
    return 0;
}
