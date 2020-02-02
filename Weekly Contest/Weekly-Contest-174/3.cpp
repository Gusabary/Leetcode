#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};




class Solution {
public:
    int maxProduct(TreeNode* root) {
        traverse(root);
        int total = vals.back();
        int mindiff = -1;
        for (int val : vals) {
            if (abs(2*val - total) < mindiff || mindiff == -1) {
                mindiff = abs(2 * val - total);
            }
        }
        const int modnum = 1000000007;
        int big = ((total + mindiff) / 2) % modnum;
        int small = ((total - mindiff) / 2) % modnum;
        int ans = big;
        for (int i = 0; i < small; i++) {
            ans = (ans + ans) % modnum;
        }
        return ans;
    }
    int traverse(TreeNode *cnt) {
        if (!cnt)
            return 0;
        int leftval = traverse(cnt->left);
        int rightval = traverse(cnt->right);
        int cntval = cnt->val + leftval + rightval;
        vals.push_back(cntval);
        return cntval;
    }
private:
    vector<int> vals;
};