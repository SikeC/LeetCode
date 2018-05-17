#include <iostream>
#include <string>
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

class Codec
{
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        queue<TreeNode *> layers;
        string ret;
        if (!root)
            return ret;
        layers.push(root);
        while (!layers.empty())
        {
            TreeNode *tmp = layers.front();
            layers.pop();
            if (tmp == NULL)
            {
                ret.push_back(',');
                ret.push_back('N');
            }
            else
            {
                ret.push_back(',');
                string s;
                int val = tmp->val;
                while (val)
                {
                    s.push_back(val % 10 + '0');
                    val /= 10;
                }
                reverse(s.begin(), s.end());
                ret += s;
                layers.push(tmp->left);
                layers.push(tmp->right);
            }
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        queue<TreeNode *> layers;
        int num = 0;
        bool left = true;
        bool isN=false;
        if (data.empty())
            return NULL;
        TreeNode *root = new TreeNode(0);
        int s;
        for (s = 1; data[s] != ','; s++)
        {
            num = num * 10 + data[s] - '0';
        }
        root->val = num;
        num = 0;
        layers.push(root);
        for (int i = s + 1; i < data.size(); i++)
        {
            if (data[i] != ',')
            {
                if (data[i] != 'N')
                {
                    num = num * 10 + data[i] - '0';
                }
                else
                    isN=true;
            }
            else
            {
                if (!isN)
                {
                    TreeNode *tmp = layers.front();
                    if (left)
                    {
                        tmp->left = new TreeNode(num);
                        layers.push(tmp->left);
                    }
                    else
                    {
                        tmp->right = new TreeNode(num);
                        layers.push(tmp->right);
                    }
                }
                else
                    isN=false;
                left = !left;
                num = 0;
                if(left)
                    layers.pop();
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
    TreeNode root(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.right->left = new TreeNode(4);
    root.right->right = new TreeNode(5);
    Codec c;
    string ret = c.serialize(&root);
    TreeNode *tmp = c.deserialize(ret);
    return 0;
}