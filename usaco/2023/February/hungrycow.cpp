#include <iostream>
#include <algorithm>

int main()
{
    long long n = 0, t = 0, left = 0, total = 0, prevd = 0, d[100005] = {0}, b[100005] = {0};

    std::cin >> n >> t;

    for (int i = 0; i < n; i++)
    {
        std::cin >> d[i] >> b[i];
    }
    d[n] = t + 1;
    b[n] = 0;

    for (int i = 0; i <= n; i++)
    {
        total += b[i];
        left -= d[i] - prevd;
        prevd = d[i];
        left = std::max(left, 0ll) + b[i];
    }

    std::cout << total - left << '\n';
    return 0;
}