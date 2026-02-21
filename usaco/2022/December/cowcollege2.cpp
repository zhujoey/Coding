#include <iostream>
#include <algorithm>

int main()
{
    long long n, c[100000], ans = 0, tuition, temp;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> c[i];
    }
    std::sort(c, c + n);
    for (int i = 0; i < n; ++i)
    {
        temp = (n - i) * c[i];
        if (temp > ans)
        {
            ans = temp;
            tuition = c[i];
        }
    }
    std::cout << ans << " " << tuition;
    return 0;
}