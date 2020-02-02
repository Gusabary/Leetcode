#include <vector>
#include <map>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        // map<string, int> num;
        vector<pair<int, int>> num;
        for (int a : arr) {
            bool ok = false;
            for (auto it = num.begin(); it != num.end(); it++) {
                if (it->first == a) {
                    it->second++;
                    ok = true;
                    break;
                }
            }
            if (!ok)
                num.push_back(make_pair(a, 1));
        }

        vector<int> v;
        int total = 0;
        for (auto it = num.begin(); it != num.end(); it++) {
            bool ok = false;
            total += it->second;
            for (auto vt = v.begin(); vt != v.end(); vt++) {
                if (*vt < it->second) {
                    v.insert(vt, it->second);
                    ok = true;
                    break;
                }
            }
            if (!ok)
                v.push_back(it->second);
        }

        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            cnt += v[i];
            if (2*cnt >= total) {
                return i + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> v = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
    int ans = s.minSetSize(v);
    cout << ans << endl;
    system("pause");
    return 0;
}