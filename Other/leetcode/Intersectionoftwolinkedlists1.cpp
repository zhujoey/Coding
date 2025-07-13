struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *heada, ListNode *headb)
    {
        ListNode *startb = headb;
        while (heada != nullptr)
        {
            while (headb != nullptr)
            {
                if (headb == heada)
                {
                    return heada;
                }
                headb = headb->next;
            }
            headb = startb;
            heada = heada->next;
        }
        return nullptr;
    }
};