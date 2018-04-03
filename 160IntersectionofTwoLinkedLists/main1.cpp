#include <iostream>
#include <stack>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        stack<ListNode *> myStackA;
        stack<ListNode *> myStackB;
        ListNode *tmp;
        tmp = headA;
        if (!headA || !headB)
            return NULL;
        while (headA && headB)
        {
            myStackA.push(headA);
            myStackB.push(headB);
            headA = headA->next;
            headB = headB->next;
        }

        while (!headA && headB)
        {
            myStackB.push(headB);
            headB = headB->next;
        }
        while (headA && !headB)
        {
            myStackA.push(headA);
            headA = headA->next;
        }

        while (!myStackA.empty() && !myStackB.empty())
        {
            if (myStackA.top()->val == myStackB.top()->val)
            {
                myStackA.pop();
                myStackB.pop();
                if (myStackA.empty() && myStackB.empty())
                {
                    if (myStackA.empty() || myStackB.empty())
                        return tmp;
                    else
                        return myStackA.empty() ? myStackB.top()->next : myStackA.top()->next;
                }
            }
            else
            {
                return myStackA.top()->next;
            }
        }
        return NULL;
    }
};
int main()
{
    ListNode a(1);
    ListNode b(1);
    ListNode *ret;
    Solution s;
    ret = s.getIntersectionNode(&a, &b);
    return 0;
}