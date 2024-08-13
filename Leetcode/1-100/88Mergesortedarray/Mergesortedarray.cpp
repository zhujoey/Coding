#include <vector>

class Solution
{
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        if (m == 0)
        {
            nums1.swap(nums2);
            return;
        }
        else if (n == 0)
        {
            return;
        }

        int i = 0;
        int j = 0;
        std::vector<int> result = {};

        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                result.push_back(nums1[i]);
                ++i;
            }
            else
            {
                result.push_back(nums2[j]);
                ++j;
            }
        }
        //merge lists

        if (i >= m)
        {
            for (j; j < n; ++j)
            {
                result.push_back(nums2[j]);
            }
        }
        else if (j >= n)
        {
            for (i; i < m; ++i)
            {
                result.push_back(nums1[i]);
            }
        }
        //add the rest of the lists

        nums1.swap(result);
    }
};