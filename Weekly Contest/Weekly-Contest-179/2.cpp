class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        set<int> off(light.begin(), light.end());
        set<int> on;
        set<int> blue;
        int ans = 0;

        for (int i : light) {
            off.erase(i);
            if (!off.empty() && *off.begin() < i) {
                on.insert(i);
            }
            else {
                blue.insert(i);
                int last = i;
                while (true) {
                    if (!on.empty() && *on.begin() == last + 1) {
                        on.erase(last + 1);
                        blue.insert(last + 1);
                        last++;
                    }
                    else {
                        break;
                    }
                }
                if (on.empty()) {
                    ans++;
                }
            }

//             cout << "off: ";
//             for (auto it = off.begin(); it != off.end(); it++) {
//                 cout << *it << ' ';
//             }
//             cout << endl;
//                         cout << "on: ";

//              for (auto it = on.begin(); it != on.end(); it++) {
//                 cout << *it << ' ';
//             }
//             cout << endl;
//                         cout << "blue: ";

//              for (auto it = blue.begin(); it != blue.end(); it++) {
//                 cout << *it << ' ';
//             }
//             cout << endl;
//             cout << endl;
        }

        return ans;
    }
};