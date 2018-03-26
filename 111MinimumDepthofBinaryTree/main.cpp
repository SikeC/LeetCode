#include <iostream>
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
    int minDepth(TreeNode *root)//就用求最大深度的逻辑求就行
    {
        if (!root)
            return 0;
        int l = minDepth(root->left) + 1;
        int r = minDepth(root->right) + 1;
        if (l == 1)
            return r;
        if (r == 1)
            return l;
        return l < r ? l : r;
    }
};