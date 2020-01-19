#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<set<int> *>> f;
        cout << "***" << endl;
        f.reserve(n+1);
        for (vector<set<int> *> fi : f) {
            fi.reserve(n+1);
        }
        cout << "***" << endl;

        for (int i = 0; i <= n; i++) {

            set<int> t;
            cout << &t << endl;
            cout << f[i][0] << endl;
            f[i][0] = &t;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {

                set<int> *x;

                if (ranges[i] == 0)
                    x = f[i - 1][j - 1];
                set<int> tmp;
                for (int jj = i - ranges[i]; jj <= i + ranges[i]; jj++) {
                    if (jj >= 0 && jj <= n) {
                        tmp.insert(jj);
                    }
                }
                for (int fi : *(f[i-1][j-1])) {
                    tmp.insert(fi);
                }
                x = &tmp;

                if (i == j || x->size() > f[i-1][j]->size())
                    f[i][j] = x;
                else
                    f[i][j] = f[i - 1][j];
            }
        }
        cout << "***" << endl;

        for (int i = 1; i <= n + 1; i++) {
            if (f[n][i]->size() == n+1)
                return i;
        }
        return -1;
    }

    set<int> add(set<int> f, int a, int cnt, int n) {
        if (a == 0)
            return f;
        set<int> tmp;
        for (int i = cnt - a; i <= cnt + a; cnt++) {
            if (i >= 0 && i <= n) {
                tmp.insert(i);
            }
        }
        for (int fi : f) {
            tmp.insert(fi);
        }
        return tmp;
    }
};

int main() {
    int n = 5;
    vector<int> v = {3, 4, 1, 1, 0, 0};
    Solution s;
    s.minTaps(n, v);
    return 0;
}