#include <iostream>
#include <queue>

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
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> Q;
        Q.push(root);
        TreeNode *cnt = Q.front();
        bool hasReachFinalNode = false;
        while (true)
        {
            if (cnt->left == NULL)
                hasReachFinalNode = true;
            if (hasReachFinalNode && (cnt->left != NULL || cnt->right != NULL))
                return false;
            if (cnt->right == NULL)
                hasReachFinalNode = true;
            if (cnt->left != NULL)
                Q.push(cnt->left);
            if (cnt->right != NULL)
                Q.push(cnt->right);
            Q.pop();
            if (Q.size() == 0)
                return true;
            cnt = Q.front();
        }
    }
};

int main()
{

    system("pause");
    return 0;
}