#include <iostream>
#include <cmath>

int main()
{
    long long a, goal = 0, prev = 0;
    int n, ans = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a;
        ans += std::abs(a - goal);
        goal = 2 * a - prev;
        prev = a;
    }
    std::cout << ans;
    return 0;
}