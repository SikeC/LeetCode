#include <iostream>
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
    bool hasCycle(ListNode *head)//利用追逐问题一样，如果是个圆，跑得快的一定会再次遇上跑得慢的
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};