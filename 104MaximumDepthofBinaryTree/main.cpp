#include <iostream>
using namespace std;

static string opt =[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return "";
}();

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
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int nleft = maxDepth(root->left);
        int nright = maxDepth(root->right);
        return nleft > nright ? nleft + 1 : nright + 1;
    }
};