#include <iostream>
#include <vector>
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
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
    bool isPalindrome(ListNode *head)
    {
        ListNode *tmp;
        vector<int> l;
        if (!head)
            return true;
        tmp = head;
        while (tmp)
        {
            l.push_back(tmp->val);
            tmp = tmp->next;
        }
        while (!l.empty())
        {
            if (l.back()!= head->val)
                return false;
            else
            {
                l.pop_back();
                head = head->next;
            }
        }
        return true;
    }
};

int main()
{
    ListNode root(1);
    ListNode node(2);
    Solution s;
    root.next=&node;
    s.isPalindrome(&root);
    return 0;
}