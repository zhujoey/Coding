#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        int answer = 0;
        int min = prices[0];
        for (int i = 0; i < prices.size(); ++i)
        {
            if (prices[i] < min)
            {
                min = prices[i];
            }

            if (prices[i] - min > answer)
            {
                answer = prices[i] -  min;
            }
        }
    
        return answer;
    }
};