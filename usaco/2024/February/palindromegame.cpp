#include <iostream>
#include <string>

int main()
{
    short t;
    std::string num;
    std::cin >> t;
    while (t--)
    {
        std::cin >> num;
        if (!(num[num.size() - 1] - 48))
        {
            std::cout << "E\n";
        }
        else
        {
            std::cout << "B\n";
        }
    }
    return 0;
}