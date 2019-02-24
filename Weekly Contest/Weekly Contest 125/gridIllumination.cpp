#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    struct mapT
    {
        int light = 0;
        bool hasLamp = false;
    };

    vector<int> gridIllumination(int N, vector<vector<int>> &lamps, vector<vector<int>> &queries)
    {
        vector<mapT> tmp(N);
        vector<vector<mapT>> map(N, tmp);
        for (int i = 0; i < lamps.size(); i++)
        {
            map[lamps[i][0]][lamps[i][1]].hasLamp = true;
            for (int i = 0; i < N; i++)
                map[lamps[i][0]][i].light++;
            for (int i = 0; i < N; i++)
                map[i][lamps[i][1]].light++;
            map[lamps[i][0]][lamps[i][1]].light--;
            int d = 1;
            while (lamps[i][0] + d < N && lamps[i][1] + d < N)
            {
                map[lamps[i][0] + d][lamps[i][1] + d].light++;
                d++;
            }
            d = 1;
            while (lamps[i][0] + d < N && lamps[i][1] - d >= 0)
            {
                map[lamps[i][0] + d][lamps[i][1] - d].light++;
                d++;
            }
            d = 1;
            while (lamps[i][0] - d >= 0 && lamps[i][1] - d >= 0)
            {
                map[lamps[i][0] - d][lamps[i][1] - d].light++;
                d++;
            }
            d = 1;
            while (lamps[i][0] - d >= 0 && lamps[i][1] + d < N)
            {
                map[lamps[i][0] - d][lamps[i][1] + d].light++;
                d++;
            }
        }
        vector<int> ans;
        for (int ii = 0; ii < queries.size(); ii++)
        {
            int x = queries[ii][0], y = queries[ii][1];
            if (map[x][y].light > 0)
                ans.push_back(1);
            else
                ans.push_back(0);
            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    if (x + dx >= 0 && x + dx < N && y + dy >= 0 && y + dy < N && map[x + dx][y + dy].hasLamp)
                    {
                        map[x + dx][y + dy].hasLamp = false;
                        for (int i = 0; i < N; i++)
                            map[x + dx][i].light--;
                        for (int i = 0; i < N; i++)
                            map[i][y + dy].light--;
                        map[x + dx][y + dy].light++;
                        int d = 1;
                        while (x + dx + d < N && y + dy + d < N)
                        {
                            map[x + dx + d][y + dy + d].light--;
                            d++;
                        }
                        d = 1;
                        while (x + dx + d < N && y + dy - d >= 0)
                        {
                            map[x + dx + d][y + dy - d].light--;
                            d++;
                        }
                        d = 1;
                        while (x + dx - d >= 0 && y + dy - d >= 0)
                        {
                            map[x + dx - d][y + dy - d].light--;
                            d++;
                        }
                        d = 1;
                        while (x + dx - d >= 0 && y + dy + d < N)
                        {
                            map[x + dx - d][y + dy + d].light--;
                            d++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};