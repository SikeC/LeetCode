#include <iostream>
#include <queue>
using namespace std;

int key=[](){
    std::ios::sync_with_stdio(false);
    return 0;
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
    bool isSymmetric(TreeNode *root) // 从跟节点开始就是比较左右子树，且左子树的左子树为右子树的右子树，用一个队列按顺序存入在取出就行
                                     // 也可以用中序遍历的方法把所有左子树存进一个队列，然后取出与右子树
    {
        if (root == NULL)
        {
            return true;
        }
        queue<TreeNode *> tmp;

        tmp.push(root->left);
        tmp.push(root->right);

        while (!tmp.empty())
        {
            TreeNode *node1 = tmp.front();
            tmp.pop();
            TreeNode *node2 = tmp.front();
            tmp.pop();

            if ((!node1 && node2) || (node1 && !node2))
            {
                return false;
            }

            if (node1 && node2)
            {
                if (node1->val != node2->val)
                {
                    return false;
                }
                tmp.push(node1->left);
                tmp.push(node2->right);
                tmp.push(node1->right);
                tmp.push(node2->left);
            }
        }

        return true;
    }
};

int main()
{
    return 0;
}