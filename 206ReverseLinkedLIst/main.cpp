#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *reverseList(ListNode *head)//用三个指针来表示前中后三个节点，用时8ms
    {
        ListNode *tmp;
        ListNode *cursor;
        cursor = head;
        tmp = NULL;
        while (cursor)
        {
            cursor = cursor->next;
            head->next = tmp;
            tmp = head;
            tmp = cursor;
        }
        return tmp;
    }
};