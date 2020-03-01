#include <vector>

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    bool find(ListNode* head, TreeNode *node) {
        if (!head)
            return true;
        if (!node)
            return false;
        if (node->val != head->val)
            return false;
        if (find(head->next, node->left))
            return true;
        if (find(head->next, node->right))
            return true;
    }
    bool dfs(ListNode* head, TreeNode *node) {
        if (!node)
            return false;
        if (find(head, node))
            return true;
        if (dfs(head, node->left))
            return true;
        if (dfs(head, node->right))
            return true;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, root);
    }
};