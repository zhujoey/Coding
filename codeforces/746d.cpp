#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int n, k, a, b;
    std::cin >> n >> k >> a >> b;
    char front = 'G', back = 'B';
    std::string ans;
    if (a < b)
    {
        std::swap(a, b);
        std::swap(front, back);
    }
    while (a > b && b > 0)
    {
        ans += std::string(std::min(k, a - b + 1), front);
        ans += back;
        a -= std::min(k, a - b + 1);
        --b;
    }
    if (b == 0 && a > k)
    {
        std::cout << "NO";
        return 0;
    }
    while (a > 0 || b > 0)
    {
        ans += std::string(std::min(k, a), front);
        ans += std::string(std::min(k, b), back);
        a -= k;
        b -= k;
    }
    std::cout << ans;

    return 0;
}