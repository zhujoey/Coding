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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *templ1 = l1;
        ListNode *templ2 = l2;
        int l1len = 0;
        int l2len = 0;
//!
        while (templ1 != nullptr)
        {
            ++l1len;
            templ1 = templ1->next;
        }
        while (templ2 != nullptr)
        {
            ++l2len;
            templ2 = templ2->next;
        }
//!

        if (l2len > l1len)
        {
            l1.swap(l2);
        }
        
        ListNode *head = l1;

        while (l1->next != nullptr && l2->next != nullptr)
        {
            l1->val += l2->val;
            if (l1->val >= 10)
            {
                ++l1->next->val;
                l1->val -= 10;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        l1->val += l2->val;

        while (l1 != nullptr && l1->next != nullptr)
        {
            if (l1->val >= 10)
            {
                ++l1->next->val;
                l1->val -= 10;
            }
            l1 = l1->next;
        }

        if (l1 != nullptr && l1->val >= 10)
        {
            ListNode* newdigit = new ListNode(1);
            l1->val -= 10;
            l1->next = newdigit;
            cout << l1->next->val;
        }

        return head;
    }
};