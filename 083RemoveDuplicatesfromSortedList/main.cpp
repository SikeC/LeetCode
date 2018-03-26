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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *tmp;
        if (head == NULL)
            return head;
        tmp = head;
        while (tmp->next != NULL && tmp != NULL)
        {
            if (tmp->next->val == tmp->val)
                tmp->next = tmp->next->next;
            else
                tmp = tmp->next;
        }
        return head;
    }
};

int main()
{
    return 0;
}