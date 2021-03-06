#include <iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution  //用递归实现
{
  public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL || q == NULL)
            return (p == q);
        return ((p->val == q->val) & isSameTree(p->left, q->left) & isSameTree(p->right, q->right));
    }
};

int main()
{
    return 0;
}