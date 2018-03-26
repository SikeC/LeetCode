#include <iostream>
#include <vector>
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
    TreeNode *sortedArrayToBST(vector<int> &nums) //将排序后的数组进行二分，每次中点作为一个根节点
    {
        int mid;
        TreeNode *root;
        if (nums.size() == 0)
            return NULL;
        mid = nums.size() / 2;
        root = new TreeNode(nums[mid]);
        if (nums.size() == 1)
            return root;
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};

int main()
{
    vector<int> a(5);
    Solution s;
    a[0] = 0;

    a[1] = 1;

    a[2] = 2;

    a[3] = 3;

    a[4] = 4;
    s.sortedArrayToBST(a);
    return 0;
}