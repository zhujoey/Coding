#include <algorithm>
#include <cmath>
#include <string>

class Solution
{
public:
    int titleToNumber(std::string columntitle)
    {
        std::reverse(columntitle.begin(), columntitle.end());
        int ans = 0;
        for (int i = 0; i < columntitle.size(); ++i)
        {
            ans += (columntitle[i] - '@') * pow(26, i);
        }
        return ans;
    }
};