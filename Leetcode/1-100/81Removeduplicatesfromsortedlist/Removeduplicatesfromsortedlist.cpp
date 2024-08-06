#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        int lastnum = head->val;
        ListNode *result = head;
        ListNode *tail = head;
        head = head->next;
        while (head != nullptr)
        {
            if (head->val != lastnum)
            {
                tail->next = head;
                tail = head;
                lastnum = head->val;
            }
            head = head->next;
        }
        tail->next = nullptr;
        return result;
    }
};