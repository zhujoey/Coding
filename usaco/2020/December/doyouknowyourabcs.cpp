#include <iostream>
#include <algorithm>

int main()
{
    int nums[7], a, b, c;
    for (int i = 0; i < 7; i++)
    {
        std::cin >> nums[i];
    }
    std::sort(nums, nums + 7);
    a = nums[0];
    b = nums[1];
    c = nums[6] - a - b;
    std::cout << a << " " << b << " " << c << "\n";
    return 0;
}