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
    void recoverTree(TreeNode* root)
    {
        std::vector<int> tree = inorderTraversal(root);
        int swap1 = 0;
        int swap2 = 0;
        bool changed = false;

        for (int i = 0; i < tree.size() - 1; ++i)
        {
            if (tree[i] > tree[i + 1])
            {
                if (!changed)
                {
                    swap1 = tree[i];
                    swap2 = tree[i + 1];
                    changed = true;
                }
                else
                {
                    swap2 = tree[i + 1];
                }
            }
        }

        swapping(root, swap1, swap2);
    }
    void swapping(TreeNode* &root, const int &swap1, const int &swap2)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->val == swap1)
        {
            root->val = swap2;
        }
        else if (root->val == swap2)
        {
            root->val = swap1;
        }

        if (root->left != nullptr)
        {
            swapping(root->left, swap1, swap2);
        }

        if (root->right != nullptr)
        {
            swapping(root->right, swap1, swap2);
        }
    }
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        if (root == nullptr)
        {
            return {};
        }
        std::vector<int> answer = {};
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