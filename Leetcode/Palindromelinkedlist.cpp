/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        std::vector<int> nums = {};

        while (head != nullptr)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        if (nums == std::vector<int>(nums.rbegin(), nums.rend()))
        {
            return true;
        }

        return false;
    }
};