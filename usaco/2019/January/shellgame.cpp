#include <iostream>
#include <algorithm>

int main()
{
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n, pos1 = 1, pos2 = 2, pos3 = 3, valid1 = 0, valid2 = 0, valid3 = 0, a, b, g;
    std::cin >> n;
    while (n--)
    {
        std::cin >> a >> b >> g;
        if (a == pos1)
        {
            if (b == pos2)
            {
                std::swap(pos1, pos2);
            }
            else if (b == pos3)
            {
                std::swap(pos1, pos3);
            }
        }
        else if (a == pos2)
        {
            if (b == pos3)
            {
                std::swap(pos3, pos2);
            }
            else if (b == pos1)
            {
                std::swap(pos1, pos2);
            }
        }
        else if (a == pos3)
        {
            if (b == pos2)
            {
                std::swap(pos3, pos2);
            }
            else if (b == pos1)
            {
                std::swap(pos1, pos3);
            }
        }
        if (pos1 == g)
        {
            ++valid1;
        }
        else if (pos2 == g)
        {
            ++valid2;
        }
        else if (pos3 == g)
        {
            ++valid3;
        }
    }

    std::cout << std::max(std::max(valid1, valid2), valid3);

    return 0;
}