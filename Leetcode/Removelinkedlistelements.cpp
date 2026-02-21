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
    ListNode* removeElements(ListNode* head, int val)
    {
        while (head != nullptr && head->val == val)
        {
            head = head->next;
        }

        if (head == nullptr)
        {
            return head;
        }
        
        ListNode *ans = head;
        ListNode *tail = head;

        while (head != nullptr)
        {
            if (head->val != val)
            {
                tail = head;
            }
            else
            {
                tail->next = head->next;
            }

            head = head->next;
        }
        
        return ans;
    }
};