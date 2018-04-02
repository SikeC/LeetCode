#include <iostream>
using namespace std;
class MinStack
{
  public:
    /** initialize your data structure here. */
    MinStack *next;
    MinStack *head;
    int val;
    MinStack()
    {
        head = NULL;
        next = NULL;
        val = 0;
    }

    void push(int x)
    {
        if (!head)
        {
            this->head = this;
            this->val = x;
        }
        else
        {
            MinStack *tmp = new MinStack;
            tmp->next = this->head;
            this->head = tmp;
            tmp->val = x;
        }
    }

    void pop()
    {
        if (this->head == this)
            this->head = NULL;
        else
        {
            MinStack *tmp;
            tmp = this->head;
            this->head = this->head->next;
            delete[] tmp;
        }
    }

    int top()
    {
        return this->head->val;
    }

    int getMin()
    {
        int min;
        MinStack *tmp;
        if (this->head == NULL)
            return 0;
        tmp = this->head;
        min = tmp->val;
        while (tmp != NULL)
        {
            if (min > tmp->val)
                min = tmp->val;
            else
                tmp = tmp->next;
        }
        return min;
    }
};