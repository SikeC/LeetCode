#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    vector<vector<int> > levelOrderBottom(TreeNode *root)
    {
        queue<TreeNode*> tree;//用队列记录每次进去的然后每一层用count计数，下一层用next_count计数，每次把这一层的从左到右存入队列，然后取出最左边的存下一层的
        vector<int> tmp;
        vector<vector<int> >ret;
        int next_count =0;
        int count=1;
        TreeNode *node;
        if(root == NULL)
        {
            return ret;
        }
        tree.push(root);
        while(!tree.empty())
        {
            node = tree.front();
            tree.pop();
            tmp.push_back(node->val);
            count--;
            if(node->left!=NULL)
            {
                tree.push(node->left);
                next_count++;
            }
            if(node->right!=NULL)
            {
                tree.push(node->right);
                next_count++;
            }
             if(count == 0)
            {
                ret.push_back(tmp);
                tmp.clear();
                count = next_count;
                next_count = 0;
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};