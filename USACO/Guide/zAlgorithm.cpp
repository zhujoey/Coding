#include <iostream>

int main()
{
    std::string input;
    std::cin >> input;
    int count = 0;

    std::cout << input.size() << " ";

    for (int i = 1; i < input.size(); ++i)
    {
        count = 0;
        
        for (int j = i; j < input.size(); ++j)
        {
            if (input[j - i] == input[j])
            {
                ++count;
            }
            else
            {
                break;
            }
        }
        
        std::cout << count << " ";
    }

    return 0;
}