class Solution
{
public:
    bool isHappy(int n)
    {
        std::string tempnumber = "";
        std::vector<int> number = {};
        std::vector<int> nums = {};

        while (n != 1)
        {
            if (std::find(nums.begin(), nums.end(), n) != nums.end())
            {
                return false;
            }

            nums.push_back(n);
            tempnumber = std::to_string(n);
            number = {};
            for (int i = 0; i < tempnumber.size(); ++i)
            {
                number.push_back(tempnumber[i] - '0');
            }

            n = 0;

            for (int i = 0; i < number.size(); ++i)
            {
                number[i] = pow(number[i], 2);
                n += number[i];
            }
        }

        return true;
    }
};