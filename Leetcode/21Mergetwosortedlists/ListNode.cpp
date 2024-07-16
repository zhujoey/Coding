struct ListNode
{
    int val;
    ListNode *next;  // pointer


public:
    // constructor
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int main()
{
    ListNode n;
    n.val = 0;

    n.val = 0;
    n.next = nullptr;

    ListNode n2;
    n.next = &n2;

    n.next->val = 1;
    n.next->next = nullptr;

    ListNode n3;
    n.next = &n3;
    n.next->val = 3;

    n.val;
    n2.val;
    n3.val;

//    std::cout << n.val;
}