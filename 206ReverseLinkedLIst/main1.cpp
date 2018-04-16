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
    ListNode *reverseList(ListNode *head) //用递归的方法顺次把每个节点压入栈，当前节点为head，他的下一个节点回头指向他本身，只有后面的连续性在变化，前面节点连续性不变，用时8ms
    {
        ListNode *cursor;
        if(!head||!head->next)
            return head;
        cursor=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return cursor;
    }
};