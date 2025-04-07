#include <string>

class Solution
{
public:
    std::string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        
        return RLE(countAndSay(n - 1));
    }
    std::string RLE(std::string nums)
    {
        char current = nums[0];
        int currentamount = 1;
        std::string answer = "";
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != current)
            {
                answer += (std::to_string(currentamount));
                answer.push_back(current);
                currentamount  = 1;
                current = (nums[i]);
            }
            else
            {
                ++currentamount;
            }
        }

        answer += (std::to_string(currentamount));
        answer.push_back(current);

        return answer;
    }
};