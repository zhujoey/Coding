#include <iostream>

int main()
{
    int n, odd = 0, even = 0, x;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x;
        if (x % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    while (odd > even)
    {
        odd -= 2;
        ++even;
    }
    if (even > odd + 1)
    {
        even = odd + 1;
    }
    
    std::cout << even + odd << "\n";
}