#include <string>
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
    std::vector<std::string> binaryTreePaths(TreeNode* root)
    {
        //base case
        if (root->left == nullptr && root->right == nullptr)
        {
            return {std::to_string(root->val)};
        }

        std::vector<std::string> left = {};
        std::vector<std::string> right = {};

        //recursion
        if (root->left != nullptr)
        {
            left = binaryTreePaths(root->left);
        }
        if (root->right != nullptr)
        {
            right = binaryTreePaths(root->right);
        }

        //adding to the strings
        for (int i = 0; i < left.size(); ++i)
        {
            left[i] = std::to_string(root->val) + "->" + left[i];
        }
        for (int i = 0; i < right.size(); ++i)
        {
            right[i] = std::to_string(root->val) + "->" + right[i];
        }

        //combining vectors
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};