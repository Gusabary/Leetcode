#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> power;
        for (int i = 0; i < mat.size(); i++) {
            bool ok = false;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 0) {
                    ok = true;
                    power.push_back(make_pair(i, j));
                    break;
                }
            }
            if (!ok)
                power.push_back(make_pair(i,mat[i].size()));
        }

        for (int i = 0; i < mat.size()-1; i++) {
            for (int j = i; j < mat.size(); j++) {
                if (power[i].second > power[j].second || (power[i].second == power[j].second && power[i].first > power[j].first)) {
                    pair<int, int> p = power[i];
                    power[i] = power[j];
                    power[j] = p;
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(power[i].first);
        }
        return ans;
    }
};

int main() {
    cout << "Hello" << endl;

    system("pause");
    return 0;
}
