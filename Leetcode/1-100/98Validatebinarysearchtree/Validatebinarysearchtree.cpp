#include <algorithm>

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
    bool isValidBST(TreeNode* root)
    {
        if (root->left == nullptr)
        {
            if (root->right == nullptr)
            {
                return true;
            }
            else
            {
                return min(root->right) > root->val && isValidBST(root->right);
            }
        }
        else if (root->right == nullptr)
        {
            return max(root->left) < root->val && isValidBST(root->left);
        }
        return max(root->left) < root->val && min(root->right) > root->val && isValidBST(root->right) && isValidBST(root->left);
    }

    int max(TreeNode* root)
    {
        if (root->left == nullptr)
        {
            if (root->right == nullptr)
            {
                return root->val;
            }
            else
            {
                return std::max(max(root->right), root->val);
            }
        }
        else if (root->right == nullptr)
        {
            return std::max(max(root->left), root->val);
        }
        else
        {
            return std::max({max(root->left), max(root->right), root->val});
        }
    }
    
    int min(TreeNode* root)
    {
        if (root->left == nullptr)
        {
            if (root->right == nullptr)
            {
                return root->val;
            }
            else
            {
                return std::min(min(root->right), root->val);
            }
        }
        else if (root->right == nullptr)
        {
            return std::min(min(root->left), root->val);
        }
        else
        {
            return std::min({min(root->left), min(root->right), root->val});
        }
    }
};