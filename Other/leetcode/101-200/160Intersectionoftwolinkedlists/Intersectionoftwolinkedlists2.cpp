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
        int alength = 0;
        int blength = 0;

        ListNode* countlengtha = heada;
        ListNode* countlengthb = headb;        

        while (countlengtha != nullptr)
        {
            ++alength;
            countlengtha = countlengtha->next;
        }

        while (countlengthb != nullptr)
        {
            ++blength;
            countlengthb = countlengthb->next;
        }

        if (alength <= blength)
        {
            for (int i = 0; i < blength - alength; ++i)
            {
                headb = headb->next;
            }
        }
        else
        {
            for (int i = 0; i < alength - blength; ++i)
            {
                heada = heada->next;
            }
        }

        while (heada != nullptr && headb != nullptr)
        {
            if (heada == headb)
            {
                return heada;
            }
            
            heada = heada->next;
            headb = headb->next;
        }

        return nullptr;
    }
};