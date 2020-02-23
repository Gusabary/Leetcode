#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end(), greater<int>());
        vector<int> v;
        for (int d : digits) {
            v.push_back(d % 3);
        }

        // for (int vi:v)
        //     cout << vi << ' ';
        // cout << endl;

        int num1 = 0;
        int num2 = 0;
        for (int &vi : v) {
            if (vi == 1)
                num1++;
            else if (vi == 2)
                num2++;
        }
        const int sum = num1 + num2 * 2;

        if (sum % 3 == 1) {
            if (num1 >= 1) {
                for (int i = v.size() - 1; i >= 0; i--) {
                    if (v[i] == 1) {
                        v[i] = -1;
                        break;
                    }
                }
            }
            else if (num2 >= 2) {
                bool ok = false;
                for (int i = v.size() - 1; i >= 0; i--) {
                    if (v[i] == 2) {
                        v[i] = -1;
                        if (ok)
                            break;
                        ok = true;
                    }
                }
            }
        }
        else if (sum % 3 == 2) {
            if (num2 >= 1) {
                for (int i = v.size() - 1; i >= 0; i--) {
                    if (v[i] == 2) {
                        v[i] = -1;
                        break;
                    }
                }
            }
            else if (num1 >= 2) {
                bool ok = false;
                for (int i = v.size() - 1; i >= 0; i--) {
                    if (v[i] == 1) {
                        v[i] = -1;
                        if (ok)
                            break;
                        ok = true;
                    }
                }
            }
        }

        vector<char> cc = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        string ans;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != -1) {
                ans.push_back(cc[digits[i]]);
            }
        }
        if (!ans.empty() && ans.front() == '0') {
            ans = "0";
        }
        return ans;
    }
};