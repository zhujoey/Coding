class MyStack
{
public:

    std::vector<int> mystack = {};
    int temp = 0;
    
    void push(int x)
    {
        mystack.push_back(x);
    }
    
    int pop()
    {
        temp = mystack.back();
        mystack.pop_back();
        return temp;
    }
    
    int top()
    {
        return mystack.back();
    }
    
    bool empty()
    {
        return mystack.empty();
    }
};