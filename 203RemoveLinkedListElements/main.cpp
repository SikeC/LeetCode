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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *tmp=new ListNode(0);
        ListNode *cursor;
        if (head == NULL)
            return NULL;
        tmp->next = head;
        cursor=tmp;
        while (cursor->next != NULL)
        {
            if (cursor->next->val == val)
            {
                cursor->next = cursor->next->next;
            }
            else
                cursor=cursor->next;
        }
        return tmp->next;
    }
};