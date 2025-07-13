#include <vector>

struct TreeNode {
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
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        std::vector<int> nums = sums(root);
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == targetSum)
            {
                return true;
            }
        }
        return false;
    }
    std::vector<int> sums(TreeNode* root)
    {
        if (root == nullptr)
        {
            return {1001};
        }
        else if (root->left == nullptr)
        {
            if (root->right == nullptr)
            {
                return {root->val};
            }
            else
            {
                std::vector<int> nums = sums(root->right);
                int add = root->val;
                for (int i = 0; i < nums.size(); ++i)
                {
                    nums[i] += add;
                }
                return nums;
            }
        }
        else
        {
            if (root->right == nullptr)
            {
                std::vector<int> nums = sums(root->left);
                int add = root->val;
                for (int i = 0; i < nums.size(); ++i)
                {
                    nums[i] += add;
                }
                return nums;
            }
            else
            {
                std::vector<int> nums = sums(root->left);
                std::vector<int> right = sums(root->right);
                nums.insert(nums.end(), right.begin(), right.end());
                int add = root->val;
                for (int i = 0; i < nums.size(); ++i)
                {
                    nums[i] += add;
                }
                return nums;
            }
        }
    }
};