class MyQueue {
public:
    /** Initialize your data structure here. */
    deque<int> data;
    MyQueue() {
        ;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        data.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = data.front();
        data.pop_front();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        return data.front();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return data.size() == 0;
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
