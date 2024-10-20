#include <vector>

class Solution
{
public:
    int reverse(int x)
    {
        std::vector<int> num = {};
        int reversed = 0;

        while (x != 0)
        {
            num.push_back(x % 10);
            x /= 10;
        }
        for (int i = 0; i < num.size(); ++i)
        {
            if (num[i] >= 0)
            {
                if (reversed > (pow(2, 31) - 1 - num[i]) / 10)
                {
                    return 0;
                }
            }
            else
            {
                if (reversed < (0 - pow(2, 31) - num[i]) / 10)
                {
                    return 0;
                }
            }
            
            reversed *= 10;
            reversed += num[i];
        }

        return reversed;
    }
};