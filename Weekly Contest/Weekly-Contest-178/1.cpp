#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(0);
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] < nums[i] && i != j) {
                    ans[ans.size() - 1] = ans.back()+1;
                }
            }
        }
        return ans;
    }
};