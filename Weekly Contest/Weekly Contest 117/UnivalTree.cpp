#include <iostream>

using namespace std;

//Definition for a binary tree node.
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
    bool isUnivalTree(TreeNode *root)
    {
        //int value = root->val;
        if (root->left == NULL && root->right == NULL)
            return true;
        if (root->left == NULL)
            return (root->val == root->right->val && isUnivalTree(root->right));
        if (root->right == NULL)
            return (root->val == root->left->val && isUnivalTree(root->left));
        return (root->val == root->right->val && root->val == root->left->val && isUnivalTree(root->left) && isUnivalTree(root->right));
    }
};

int main()
{
    system("pause");
    return 0;
}