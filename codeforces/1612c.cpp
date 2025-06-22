#include <iostream>
 
int main()
{
    long long x, sum, half, total, t, k, left, right, mid;
    std::cin >> t;
    for (int i = 0; i < t; ++i)
    {
        std::cin >> k >> x;
        half = k * (k + 1) / 2;
        total = 2 * half - k;
        if (x >= total)
        {
            std::cout << 2 * k - 1 << "\n";
            continue;
        }
        left = 1;
        right = 2 * k - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (mid > k)
            {
                sum = half + ((2 * k - mid) + (k - 1)) * (mid - k) / 2;
            }
            else
            {
                sum = mid * (mid + 1) / 2;
            }
 
            if (sum >= x)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
            
            //std::cout << "sum: " << sum << " mid: " << mid << " left: " << left << " right: " << right << "\n";
        }
        if (sum < x)
        {
            ++mid;
        }
        std::cout << mid << "\n";
    }
    return 0;
}