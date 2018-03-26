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
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return false;
        if (sum - (root->val) == 0)
        {
            if(root->left==NULL&&root->right==NULL) //必须加一句判断是不是到了叶节点，如果不是叶子节点那么就是错的
                return true;
        }
        return hasPathSum(root->left, sum - root->val) | hasPathSum(root->right, sum - root->val);
    }
};