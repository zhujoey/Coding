struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *slow)
    {
        if (slow == nullptr ||  slow->next == nullptr)
        {
            return false;
        }

        ListNode *fast = slow->next;
        while (fast != nullptr && fast->next != nullptr && slow != nullptr)
        {
            if (fast == slow || fast->next == slow)
            {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};