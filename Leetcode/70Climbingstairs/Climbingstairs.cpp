#include <iostream>
#include <cmath>

class Solution
{
public:
    int climbStairs(float n)
    {
        if (n == 1 || n == 2)
        {
            return n;
        }
        double x = (1 + pow(5, 0.5)) / 2;
        return round((pow(x, n + 1) - pow(1 - x, n + 1)) / pow(5, 0.5));
    }
};