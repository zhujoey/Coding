#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode* convert(std::vector<int>& nums, int start, int end)
    {
        if (end <= start - 1)
        {
            return nullptr;
        }
        else if (nums.size() == 1)
        {
            return new TreeNode(nums[0]);
        }
        int center = (start + end) / 2;
        return new TreeNode(nums[center], convert(nums, start, center - 1), convert(nums, center + 1, end));
    }

    TreeNode* sortedArrayToBST(std::vector<int>& nums)
    {
        return convert(nums, 0, nums.size() - 1);
    }
};