#include <iostream>
#include <stack>
using namespace std;
static int x = []() {
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}();

class MinStack
{
  public:
    /** initialize your data structure here. */
    stack<int> data;
    stack<int> special;

    MinStack()
    {
    }

    void push(int x)
    {
        if (data.empty() || x <= special.top())
            special.push(x);
        data.push(x);
    }

    void pop()
    {
        if (data.top() == special.top())
        {
            special.pop();
        }
        data.pop();
    }

    int top()
    {
        return data.top();
    }

    int getMin()
    {
        return special.top();
    }
};