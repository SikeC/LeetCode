#include<iostream>
#include<deque>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    deque<int> a;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        a.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x;
        x=a.back();
        a.pop_back();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return a.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return a.empty();
    }
};