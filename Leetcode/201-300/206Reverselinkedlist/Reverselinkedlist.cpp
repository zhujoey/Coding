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
    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode *before = nullptr;
        ListNode *after = head;

        while (head != nullptr)
        {
            head = head->next;
            after->next = before;
            before = after;
            after = head;
        }

        return before;
    }
};