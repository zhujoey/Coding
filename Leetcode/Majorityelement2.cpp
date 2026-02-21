class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        if (nums.size() < 3)
        {
            return nums[0];
        }
        
        std::map<int, int> norepeat = {};
        auto iterator = norepeat.begin();

        for (int i = 0; i < nums.size(); ++i)
        {
            iterator = norepeat.find(nums[i]);
            if (iterator == norepeat.end())
            {
                norepeat[nums[i]] == 1;
            }
            else
            {
                ++iterator->second;
            }
            
            if (iterator->second >= nums.size() / 2)
            {
                return iterator->first;
            }
            
        }

        return 0;
    }
};