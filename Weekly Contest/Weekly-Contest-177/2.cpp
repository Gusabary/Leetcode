#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        set<int> s;
        for (int c : leftChild) {
            if (c < 0)
                continue;
            if (s.find(c) != s.end()) {
                return false;
            }
            s.insert(c);
        }
        for (int c : rightChild) {
            if (c < 0)
                continue;
            if (s.find(c) != s.end()) {
                return false;
            }
            s.insert(c);
        }
        if (s.size() == n-1)
            return true;
        return false;
    }
};