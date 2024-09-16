class MyQueue
{
public:
    
    std::deque<int> myqueue = {};
    int temp = 0;
    
    void push(int x)
    {
        myqueue.push_back(x);
    }
    
    int pop()
    {
        temp = myqueue.front();
        myqueue.pop_front();
        return temp;
    }
    
    int peek()
    {
        return myqueue.front();
    }
    
    bool empty()
    {
        return myqueue.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */