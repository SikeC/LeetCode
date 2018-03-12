#include <iostream>
#include <time.h>
using namespace std;

/*
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
  public:
    struct ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {                                     //两个已经排列好的数列，就只需要排列两个数列的第一个数就行
        struct ListNode *tmp_node = NULL; //记录当前元素头指针
        struct ListNode ret(0);           //返回的列表
        if (l1 == NULL && l2 == NULL)
        {
            return NULL;
        }
        tmp_node = &ret;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                tmp_node->next = l1;
                tmp_node = tmp_node->next;
                l1 = l1->next;
            }
            else
            {
                tmp_node->next = l2;
                tmp_node = tmp_node->next;
                l2 = l2->next;
            }
        }
        l1 == NULL ? tmp_node->next = l2 : tmp_node->next = l1;
        return ret.next;
    }
};

int main(void)
{
    struct ListNode head1(1);
    struct ListNode head2(1);
    struct ListNode *ret;
    clock_t startTime,endTime;
    double runTime;
    Solution s;
    startTime=clock();
    ret = s.mergeTwoLists(&head1, &head2);
    endTime=clock();
    runTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    cout<< runTime << 's' <<endl;

    return 0;
}