#include <vector>
#include <cmath>

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
    bool isBalanced(TreeNode* root)
    {
        int ans = balanced(root);
        if (ans == -1)
        {
            return false;
        }
        return true;
    }
    int balanced(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        
        int right = balanced(root->right);
        int left = balanced(root->left);
        if (right == -1 || left == -1)
        {
            return -1;
        }
        else if (std::abs(left - right) > 1)
        {
            return -1;
        }
        else
        {
            return std::max(left, right) + 1;
        }
    }
};