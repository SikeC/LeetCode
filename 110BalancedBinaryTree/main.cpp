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
    int depthoftree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int l = depthoftree(root->left);
        int r = depthoftree(root->right);
        return l > r ? l + 1 : r + 1;
    }
    bool isBalanced(TreeNode *root) //题意其实就是问你每一个节点下面的左右子树高度差不能超过1就行，然后就是直接判断高度差
    {
        if (root == NULL)
            return true;
        int l = depthoftree(root->left);
        int r = depthoftree(root->right);
        if (((l > r ? l - r : r - l) > 1))
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};