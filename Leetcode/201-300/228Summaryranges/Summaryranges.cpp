class Solution
{
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums)
    {
        if (nums.empty())
        {
            return {};
        }

        std::vector<int> ans = {};
        std::vector<std::string> strings = {};

        ans.push_back(nums[0]);

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] + 1 != nums[i + 1])
            {
                ans.push_back(nums[i]);
                ans.push_back(nums[i + 1]);
            }
        }

        ans.push_back(nums[nums.size() - 1]);

        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i] << endl;
        }
        for (int i = 0; i < ans.size(); i += 2)
        {
            if (ans[i] == ans[i + 1])
            {
                strings.push_back(std::to_string(ans[i]));
            }
            else
            {
                strings.push_back(std::to_string(ans[i]) + "->" + std::to_string(ans[i + 1]));
            }
        }

        return strings;
    }
};