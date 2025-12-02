#include <iostream>

int main()
{
    int n, photos = 0, totalpetals = 0, petals[100];
    bool present = false;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> petals[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            totalpetals = 0;
            present = false;
            for (int k = i; k <= j; k++)
            {
                totalpetals += petals[k];
            }
            for (int k = i; k <= j; k++)
            {
                if (petals[k] * (j - i + 1) == totalpetals)
                {
                    present = true;
                    break;
                }
            }
            if (present)
            {
                photos++;
            }
        }
    }
    std::cout << photos << std::endl;
    return 0;
}