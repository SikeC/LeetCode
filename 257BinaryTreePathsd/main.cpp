#include <iostream>
#include <vector>
#include <string>
#include <string.h>
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
    void paths(vector<string> &ret,TreeNode *root,string &s)
    {
        string tmp;
        if(!root)
        {
            ret.insert(s);
        }
        tmp=
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        
    }
};