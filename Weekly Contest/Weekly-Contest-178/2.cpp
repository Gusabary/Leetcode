#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool comp(const pair<char, vector<int>> &x, const pair<char, vector<int>> &y) {
        int i = 0;
        while (i < x.second.size()) {
            if (x.second[i] > y.second[i]) {
                return true;
            }
            if (x.second[i] < y.second[i]) {
                return false;
            }
            i++;
        }
        if (x.first < y.first) {
            return true;
        }
        return false;
    }

    string rankTeams(vector<string>& votes) {
        map<char, vector<int>> count;
        for (int i = 0; i < votes.size(); i++) {
            for (int j = 0; j < votes[i].size(); j++) {
                if (i == 0) {
                    count[votes[i][j]].resize(votes[i].size());
                }
                count[votes[i][j]][j]++;
            }
        }

        sort(count.begin(), count.end(), comp);

        string ans;
        for (auto it = count.begin(); it != count.end(); it++) {
            ans.push_back(it->first);
        }
        return ans;
    }
};

