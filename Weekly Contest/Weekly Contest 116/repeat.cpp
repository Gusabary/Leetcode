#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (auto it = A.begin(); it != A.end();it++)
            {
                if (hasAppeared.count(*it)>0)
                    return *it;
                hasAppeared.insert(*it);
            }
    }
    private:
      set<int> hasAppeared;
};

int main()
{
    Solution solve;
    vector<int> a{2,1,2,5,3,2};
    cout << solve.repeatedNTimes(a) << endl;
    system("pause");
    return 0;
}