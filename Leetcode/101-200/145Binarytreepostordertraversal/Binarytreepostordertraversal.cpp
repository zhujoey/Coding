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
    std::vector<int> postorderTraversal(TreeNode* root)
    {
        if (root == nullptr)
        {
            return {};
        }
        std::vector<int> left = postorderTraversal(root->left);
        std::vector<int> right = postorderTraversal(root->right);
        left.insert(left.end(), right.begin(), right.end());
        left.push_back(root->val);

        return left;
    }
};