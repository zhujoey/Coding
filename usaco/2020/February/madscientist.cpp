#include <iostream>
#include <string>

int main()
{
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n;
    std::cin >> n;

    std::string a;
    std::string b;
    std::cin >> a >> b;

    int ans = 0;
    bool mismatched = false;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            if (!mismatched)
            {
                mismatched = true;
                ans++;
            }
        }
        else
        {
            mismatched = false;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
