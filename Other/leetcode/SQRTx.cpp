class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 1 || x == 0)
        {
            return x;
        }
        int maxlimit = x;
        int minlimit = 0;
        long average = maxlimit / 2;
        while (maxlimit - 1 > minlimit)
        {
            if (average * average == x)
            {
                return average;
            }
            else if (average * average < x)
            {
                minlimit = average;
            }
            else
            {
                maxlimit = average;
            }
            average = (minlimit + maxlimit) / 2;
        }
        return minlimit;
    }
};