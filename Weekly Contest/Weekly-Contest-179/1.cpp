#include <string>

using namespace std;

class Solution {
public:
    string generateTheString(int n) {
        string ans;
        for (int i = 0; i < n; i++) {
            ans.push_back('a');
        }
        if (n % 2 == 0) {
            ans.back() = 'b';
        }
        return ans;
    }
};