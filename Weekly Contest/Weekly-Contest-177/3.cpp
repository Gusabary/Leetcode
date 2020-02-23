#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> closestDivisors(int num) {
        int x = num + 1;
        int a = floor(sqrt(x));
        int b;
        while (true) {
            if (x % a == 0) {
                b = x / a;
                break;
            }
            a--;
        }

        x = num + 2;
        int c = floor(sqrt(x));
        int d;
        while (true) {
            if (x % c == 0) {
                d = x / c;
                break;
            }
            c--;
        }

        if (b-a > d-c) {
            return vector({c, d});
        }
        return vector({a, b});
    }
};