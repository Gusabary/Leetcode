#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<pair<int, int>> num(N+1);
        int len=trust.size();
        for (int i = 0; i < len;i++)
        {
            num[trust[i][0]].first++;
            num[trust[i][1]].second++;
        }
        for (int i = 1; i <= N;i++)
            if (num[i].first==0&&num[i].second==N-1)
                return i;
        return -1;
    }
};

int main()
{
    Solution solve;
    int n = 3;
    vector<vector<int>> t = {{1,3},{2,3}};
    int ans = solve.findJudge(n, t);
    cout << ans << endl;
    system("pause");
    return 0;
}