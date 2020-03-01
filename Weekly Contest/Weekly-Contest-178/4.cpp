#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<int>> cost;
    vector<vector<int>> grid;

    void find(pair<int, int> cur, int curCost) {
        if (cur.first < 0 || cur.first >= n || cur.second < 0 || cur.second >= m)
            return;
        if (cost[cur.first][cur.second] == -1 || cost[cur.first][cur.second] > curCost)
            cost[cur.first][cur.second] = curCost;
        else
            return;

        if (grid[cur.first][cur.second] == 1) {
            find(make_pair(cur.first, cur.second - 1), curCost + 1);
            find(make_pair(cur.first + 1, cur.second), curCost + 1);
            find(make_pair(cur.first - 1, cur.second), curCost + 1);
            cur.second++;
        }
        else if (grid[cur.first][cur.second] == 2) {
            find(make_pair(cur.first, cur.second + 1), curCost + 1);
            find(make_pair(cur.first + 1, cur.second), curCost + 1);
            find(make_pair(cur.first - 1, cur.second), curCost + 1);
            cur.second--;
        }
        else if (grid[cur.first][cur.second] == 3) {
            find(make_pair(cur.first, cur.second + 1), curCost + 1);
            find(make_pair(cur.first, cur.second - 1), curCost + 1);
            find(make_pair(cur.first - 1, cur.second), curCost + 1);
            cur.first++;
        }
        else if (grid[cur.first][cur.second] == 4) {
            find(make_pair(cur.first, cur.second + 1), curCost + 1);
            find(make_pair(cur.first, cur.second - 1), curCost + 1);
            find(make_pair(cur.first + 1, cur.second), curCost + 1);
            cur.first--;
        }
        find(cur, curCost);
        return;
    }

    int minCost(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid.front().size();
        
        cost.resize(n);
        for (vector<int> &row : cost) {
            row.resize(m);
            fill(row.begin(), row.end(), -1);
        }

        pair<int, int> cur(0, 0);
        find(cur, 0);

        return cost[n - 1][m - 1];
    }
};

int main() {
    // vector<vector<int>> grid;
    // Solution s;
    // int ans = s.minCost(grid);
    // cout << ans << endl;
    system("pause");
    return 0;
}