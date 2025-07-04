#include <iostream>

int main()
{
    int n, s;
    std::cin >> n >> s;
    if (s - n + 1 > n)
    {
        std::cout << "YES\n";
        for (int i = 0; i < n - 1; ++i)
        {
            std::cout << 1 << " ";
        }
        std::cout << s - n + 1 << "\n";
        std::cout << n;
    }
    else
    {
        std::cout << "NO";
    }
    return 0;
}