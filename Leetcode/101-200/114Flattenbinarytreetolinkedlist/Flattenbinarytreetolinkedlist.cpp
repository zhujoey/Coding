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
    void flatten (TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        
        std::vector<int> nums = preorder(root);
        root->left = nullptr;
        make(root, nums, 1);
    }
    void make (TreeNode* root, const std::vector<int> nums, int index)
    {
        if (index >= nums.size())
        {
            return;        
        }
        root->right = new TreeNode(nums[index]);
        make(root->right, nums, index + 1);
    }
    std::vector<int> preorder (TreeNode* root)
    {
        std::vector<int> answer = {root->val};
        std::vector<int> temp = {};
        if (root->left != nullptr)
        {   
            temp = preorder(root->left);
            answer.insert(answer.end(), temp.begin(), temp.end());
        }
        if (root->right != nullptr)
        {
            temp = preorder(root->right);
            answer.insert(answer.end(), temp.begin(), temp.end());
        }

        return answer;
    }
};