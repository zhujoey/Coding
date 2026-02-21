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

    // Complexity: O(N^2)
    int sumNumbers(TreeNode* root)
    {
        std::vector<int> nums = makeNumbers(root, 0);
        int answer = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            answer += nums[i];
        }

        return answer;
    }

    std::vector<int> makeNumbers(TreeNode* root, int current)
    {
        current = current * 10 + root->val;
        std::vector<int> result = {};
        std::vector<int> temp = {};

        if (root->right != nullptr)
        {
            temp = makeNumbers(root->right, current);
            result.insert(result.end(), temp.begin(), temp.end());
        }
        if (root->left != nullptr)
        {
            temp = makeNumbers(root->left, current);
            result.insert(result.end(), temp.begin(), temp.end());
        }
        if (result.empty())
        {
            result = {current};
        }

        return result;
    }
};