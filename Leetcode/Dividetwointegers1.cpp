class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int answer = 0;

        if (divisor == 1)
        {
            return dividend;
        }
        else if (divisor == -1)
        {
            if (dividend <= -2147483648)
            {
                return 2147483647;
            }
            return 0 - dividend;
        }

        if (dividend >= 0 && divisor >= 0)
        {
            while (dividend >= divisor)
            {
                dividend -= divisor;
                ++answer;
                if (answer == 2147483647)
                {
                    break;
                }
            }
        }
        else if (dividend < 0 && divisor < 0)
        {
            while (dividend <= divisor)
            {
                dividend -= divisor;
                ++answer;
                if (answer == 2147483647)
                {
                    break;
                }
            }
        }
        else if (dividend >= 0 && divisor < 0)
        {
            ++answer;
            while (dividend >= 0)
            {                
                dividend += divisor;
                --answer;
                if (answer == -2147483648)
                {
                    break;
                }
            }
        }
        else if (dividend < 0 && divisor >= 0)
        {
            ++answer;
            while (dividend <= 0)
            {
                dividend += divisor;
                --answer;
                if (answer == -2147483648)
                {
                    break;
                }
            }
        }

        return answer;
    }
};