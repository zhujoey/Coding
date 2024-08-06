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
    bool isSymmetric(TreeNode* root)
    {
        return leftandright(root->left, root->right);
    }
    bool leftandright(TreeNode* left, TreeNode* right)
    {
        if (left != nullptr && right!= nullptr &&
            left->val == right->val &&
            leftandright(left->left, right->right) &&
            leftandright(left->right, right->left))
        {
            return true;
        }
        else if (left == nullptr && right == nullptr)
        {
            return true;
        }

        return false;
    }

};