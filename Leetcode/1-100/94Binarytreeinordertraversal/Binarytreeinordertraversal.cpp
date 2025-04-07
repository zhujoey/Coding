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
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        if (root == nullptr)
        {
            return {};
        }
        std::vector<int> answer = {};
        TreeNode *tail = root;
        if (root->left != nullptr)
        {
            answer = inorderTraversal(root->left);
        }

        answer.push_back(root->val);
        if (root->right != nullptr)
        {
            std::vector<int> temp = inorderTraversal(root->right);
            answer.insert(answer.end(), temp.begin(), temp.end());
        }
        return answer;
    }
};