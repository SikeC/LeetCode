#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *left;
        TreeNode *right;
        if (!root)
            return NULL;
        if(p->val <= q->val){
            left=p;
            right=q;
        }
        else{
            left=q;
            right=p;
        }
        if(root->val>=left->val&&root->val<=right->val)
            return root;
        if(root->val>=left->val&&root->val>=right->val)
            return lowestCommonAncestor(root->left,p,q);
        if(root->val<=left->val&&root->val<=right->val)
            return lowestCommonAncestor(root->right,p,q);
    }
};