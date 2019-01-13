#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        map<int, vector<pair<int, int>>> distance;
        for (auto it = points.begin(); it != points.end(); it++)
        {
            int x = (*it)[0];
            int y = (*it)[1];
            //cout << x << ' ' << y << endl;
            distance[x * x + y * y].push_back(make_pair(x, y));
        }
        vector<vector<int>> ans;
        int n = 0;
        for (auto it = distance.begin(); it != distance.end();it++)
        {
            //cout << it->first << endl;
            for (auto it2 = it->second.begin(); it2 != it->second.end();it2++)
            {
                vector<int> tmp(2);
                tmp[0] = it2->first;
                tmp[1] = it2->second;
                //cout << tmp[0] << ' ' << tmp[1] << endl;
                ans.push_back(tmp);
                n++;
                if (n==K)
                    break;
            }
            if (n==K)
                break;
        }
        //cout << ans[0][0] << ' ' << ans[0][1] << endl;
        return ans;
    }
};

int main()
{
    Solution solve;
    vector<vector<int>> a{{3, 3}, {5, -1},{-2,4}};
    vector<vector<int>> ans = solve.kClosest(a, 2);
    cout << ans[0][0] << ' ' << ans[0][1] << endl;
    cout << ans[1][0] << ' ' << ans[1][1] << endl;
    system("pause");
    return 0;
}