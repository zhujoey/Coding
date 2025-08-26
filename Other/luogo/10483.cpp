#include <iostream>
#include <algorithm>

int main() 
{
    long long n = 0, w = 0, left = 1, right = 0, ans = 0, mid = 0, cats[18] = {0}, cars[18] = {0};
    bool possible = true;

    std::cin >> n >> w;
    right = n;
    ans = n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> cats[i];
    }

    std::sort(cats, cats + n, std::greater<long long>());

    while (left <= right) 
    {
        mid = (left + right) / 2;
        possible = true;
        std::fill(cars, cars + 18, 0);

        for (int i = 0; i < n; ++i) 
        {
            bool placed = false;
            for (int j = 0; j < mid; ++j) 
            {
                if (cars[j] + cats[i] <= w) 
                {
                    cars[j] += cats[i];
                    placed = true;
                    break;
                }
            }
            if (!placed) 
            {
                possible = false;
                break;
            }
        }

        if (possible) 
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    std::cout << ans;
    return 0;
}