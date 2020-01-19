/**
 * Definition for a binary tree node.*/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
 
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        dfs(root, target);
        return root;
    }

    void dfs(TreeNode* cnt, int target) {
        
        if (cnt->left) {
            dfs(cnt->left, target);
        }
        if (cnt->right) {
            dfs(cnt->right, target);
        }
        if (!cnt->left && !cnt->right) {
            if (cnt->val == target) {
                cnt = nullptr;
            }
        }
        
    }
};