#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<set<int>> ss;
    vector<int> num;
    vector<int> depth;
    vector<bool> isLeaf;

    void fill(int cur) {
        int sons = ss[cur].size();
        if (sons > 0) {
            isLeaf[cur] = false;
        }
        else {
            isLeaf[cur] = true;
        }
        for (int s : ss[cur]) {
            num[s] = num[cur] * sons;
            depth[s] = depth[cur] + 1;
            fill(s);
        }
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        ss.resize(n + 1);

        set<int> hasOccurred;
        hasOccurred.insert(1);

        for (vector<int> edge : edges) {
            int a, b;
            if (hasOccurred.find(edge[0]) != hasOccurred.end()) {
                a = edge[0];
                b = edge[1];
                hasOccurred.insert(edge[1]);
            }
            else {
                a = edge[1];
                b = edge[0];
                hasOccurred.insert(edge[0]);
            }
            ss[a].insert(b);
        }

        num.resize(n + 1);
        depth.resize(n + 1);
        isLeaf.resize(n + 1);

        num[1] = 1;
        depth[1] = 0;
        fill(1);

        if (!isLeaf[target] && depth[target] < t) {
            return 0;
        }
        if (depth[target] > t) {
            return 0;
        }
        double ans = (double)1/num[target];
        return ans;
    }
};