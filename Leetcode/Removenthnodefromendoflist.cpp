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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode *deleted = head;
        ListNode *answer = head;
        
        for (int i = 0; i <= n; ++i)
        {
            if (head == nullptr)
            {
                return answer->next;
            }
            head = head->next;
        }

        while (head != nullptr)
        {
            head = head->next;
            deleted = deleted->next;
        }

        deleted->next = deleted->next->next;

        return answer;
    }
};