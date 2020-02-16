#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        const int height = grid.size();
        const int width = grid[0].size();
        for (int i = height - 1; i >= 0; i--) {
            if (grid[i][width-1] >= 0) {
                return ans;
            }
            for (int j = width-1; j >= 0; j--) {
                if (grid[i][j] < 0) {
                    ans++;
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {

    Solution s;
    vector<vector<int>> v = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    int ans = s.countNegatives(v);
    cout << ans << endl;

    system("pause");
    return 0;
}