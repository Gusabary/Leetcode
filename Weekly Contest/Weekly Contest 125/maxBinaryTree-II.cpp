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
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        //Get mid-order traversal
        midOrder(root);
        tree.push_back(val);
        int max = 0, maxN;
        for (int i = 0; i < tree.size(); i++)
            if (tree[i] > max)
            {
                max = tree[i];
                maxN = i;
            }
        TreeNode *newRoot = new TreeNode(max);
        if (maxN != 0)
        {
            vector<int> leftTree;
            leftTree.assign(tree.begin(), tree.begin() + maxN);
            construct(leftTree, newRoot, true);
        }
        if (maxN != tree.size() - 1)
        {
            vector<int> rightTree;
            rightTree.assign(tree.begin() + maxN + 1, tree.end());
            construct(rightTree, newRoot, false);
        }
        return newRoot;
    }

  private:
    void midOrder(TreeNode *root)
    {
        if (root == NULL)
            return;
        midOrder(root->left);
        tree.push_back(root->val);
        midOrder(root->right);
    }
    vector<int> tree;
    void construct(vector<int> tree, TreeNode *root, bool isLeft)
    {
        int max = 0, maxN;
        for (int i = 0; i < tree.size(); i++)
            if (tree[i] > max)
            {
                max = tree[i];
                maxN = i;
            }
        TreeNode *newRoot = new TreeNode(max);
        if (isLeft)
            root->left = newRoot;
        else
            root->right = newRoot;

        if (maxN != 0)
        {
            vector<int> leftTree;
            leftTree.assign(tree.begin(), tree.begin() + maxN);
            construct(leftTree, newRoot, true);
        }
        if (maxN != tree.size() - 1)
        {
            vector<int> rightTree;
            rightTree.assign(tree.begin() + maxN + 1, tree.end());
            construct(rightTree, newRoot, false);
        }
    }
};
