#include <vector>

using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
private:
    vector<int> v;
    TreeNode *ans;

public:
    void getValue(TreeNode *cur) {
        if (!cur) {
            return;
        }
        v.push_back(cur->val);
        getValue(cur->left);
        getValue(cur->right);
    }

    void rotate(TreeNode* root, int level, bool l1, bool l2) {
        if (level == 1) {
            return;
        }

        // r-rotate
        if (level == 2 && l1 || level == 3 && l1 && l2) {
            TreeNode *tmp = root->left;
            root->left = tmp->right;
            tmp->right = root;
            *root = *tmp;
            return;
        }

        // l-rotate
        if (level == 2 && !l1 || level == 3 && !l1 && !l2) {
            TreeNode *tmp = root->right;
            root->right = tmp->left;
            tmp->left = root;
            *root = *tmp;
            return;
        }

        // l-r-rotate
        if (level == 3 && l1 && !l2) {
            TreeNode *tmp = root->left->right;
            root->left->right = tmp->left;
            tmp->left = root->left;
            root->left = tmp;

            tmp = root->left;
            root->left = tmp->right;
            tmp->right = root;
            *root = *tmp;
            return;
        }

        // r-l-rotate
        if (level == 3 && !l1 && l2) {
            TreeNode *tmp = root->right->left;
            root->right->left = tmp->right;
            tmp->right = root->right;
            root->right = tmp;

            tmp = root->right;
            root->right = tmp->left;
            tmp->left = root;
            *root = *tmp;
            return;
        }
    }

    void insert(TreeNode* root, int val) {
        TreeNode *cur = root;
        bool l1 = false;
        bool l2 = false;
        int level = 1;
        while (true) {
            if (val > cur->val) {
                if (!cur->right) {
                    cur->right = new TreeNode(val);
                    rotate(root, level, l1, l2);
                    return;
                }
                cur = cur->right;
                if (level <= 2) {
                    level++;
                }
            }
            else {
                if (!cur->left) {
                    cur->left = new TreeNode(val);
                    rotate(root, level, l1, l2);
                    return;
                }
                cur = cur->left;
                if (level == 1) {
                    level++;
                    l1 = true;
                }
                else if (level == 2) {
                    level++;
                    l2 = true;
                }
            }
        }
    }

    TreeNode* balanceBST(TreeNode* root) {
        getValue(root);
        ans = new TreeNode(v.back());
        v.pop_back();
        for (int vi : v) {
            insert(ans, vi);
        }
        return ans;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    s.balanceBST(root);
    return 0;
}