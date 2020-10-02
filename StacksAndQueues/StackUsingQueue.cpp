/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);  
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false
Notes:

You must use only standard operations of a queue -- which means only push to back, 
peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a 
queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations 
will be called on an empty stack).
*/

class MyStack {
private:
        queue<int> q1;
        queue<int> q2;
public:
    /** Initialize your data structure here. */
    
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(q1.size()>0){
            q1.push(x);
            return;
        }
        
        q2.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int last = -1;

        if(q1.size()==0){
            while(!q2.empty()){
                last = q2.front();
                q2.pop();
                if(!q2.empty())
                    q1.push(last);
            }
        } 
        else{
            while(!q1.empty()){
                last = q1.front();
                q1.pop();
                if(!q1.empty())
                    q2.push(last);
            }
        }
        return last;
    }
    
    /** Get the top element. */
    int top() {
        int last = -1;
        if(q1.size()==0){
            while(!q2.empty()){
                last = q2.front();
                q2.pop();
                q1.push(last);
            }
        } 
        else{
            while(!q1.empty()){
                last = q1.front();
                q1.pop();
                q2.push(last);
            }
        }
        return last;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(!q1.empty() or !q2.empty())
            return false;
        else
            return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
