class Solution {
public:
    bool isPossible(vector<int>& target) {
        while (true) {
            int max = 0;
            int maxn = 0;
            for (int i = 0; i < target.size(); i++) {
                if (target[i] > max) {
                    max = target[i];
                    maxn = i;
                }
            }

            for (int i = 0; i < target.size(); i++) {
                if (i != maxn)
                    target[maxn] -= target[i];
                if (target[maxn] < 1) {
                    return false;
                }
            }

            bool ok = true;
            for (int i = 0; i <target.size(); i++) {
                if (target[i] > 1) {
                    ok = false;
                }
                if (target[i] < 1) {
                    return false;
                }
            }
            if (ok)
                return true;
        }        
    }
};