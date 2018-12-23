#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
  public:
    double minAreaFreeRect(vector<vector<int>> &points)
    {
        for (int i = 0; i < points.size(); i++)
            pointSet.insert(make_pair(points[i][0], points[i][1]));
        double minArea = 1600000001;
        for (auto it = pointSet.begin(); it != pointSet.end(); it++)
        {
            for (auto it2 = it; it2 != pointSet.end(); it2++)
            {
                if (it2 == it)
                    continue;
                //cout << it->first << ' ' << it->second << endl;
                //cout << it2->first << ' ' << it2->second << endl;
                int dx = it->second - it2->second;
                int dy = it2->first - it->first;
                int times = 1;
                for (int i = dx; i >= 2; i--)
                    if (dx % i == 0 && dy % i == 0)
                    {
                        times = i;
                        dx /= i;
                        dy /= i;
                        break;
                    }
                if (dx == 0)
                {
                    times = abs(dy);
                    dy /= times;
                }
                if (dy == 0)
                {
                    times = abs(dx);
                    dx /= times;
                }
                int i = 1;
                pair<int, int> tmpPoint1, tmpPoint2;
                while (true)
                {
                    int tmp = 40000;
                    bool isEnd = true;
                    if (it->first + i * dx >= 0 && it->first + i * dx <= tmp && it->second + i * dy >= 0 && it->second + i * dy <= tmp && it2->first + i * dx >= 0 && it2->first + i * dx <= tmp && it2->second + i * dy >= 0 && it2->second + i * dy <= tmp)
                    {
                        isEnd = false;
                        tmpPoint1 = make_pair(it->first + i * dx, it->second + i * dy);
                        tmpPoint2 = make_pair(it2->first + i * dx, it2->second + i * dy);
                        if (pointSet.count(tmpPoint1) > 0 && pointSet.count(tmpPoint2) > 0)
                        {
                            if (i * times * (dx * dx + dy * dy) < minArea)
                            {
                              /*  cout << it->first << ' ' << it->second << endl;
                                cout << it2->first << ' ' << it2->second << endl;
                                cout << tmpPoint1.first << ' ' << tmpPoint1.second << endl;
                                cout << tmpPoint2.first << ' ' << tmpPoint2.second << endl;
                                cout << i << ' ' << times << ' ' << dx << ' ' << dy << endl;*/

                                minArea = i * times * (dx * dx + dy * dy);
                               /* cout << minArea << endl;
                                cout << endl;*/
                            }
                            break;
                        }
                    }
                    if (it->first - i * dx >= 0 && it->first - i * dx <= tmp && it->second - i * dy >= 0 && it->second - i * dy <= tmp && it2->first - i * dx >= 0 && it2->first - i * dx <= tmp && it2->second - i * dy >= 0 && it2->second - i * dy <= tmp)
                    {
                        isEnd = false;
                        tmpPoint1 = make_pair(it->first - i * dx, it->second - i * dy);
                        tmpPoint2 = make_pair(it2->first - i * dx, it2->second - i * dy);
                        if (pointSet.count(tmpPoint1) > 0 && pointSet.count(tmpPoint2) > 0)
                        {
                            if (i * times * (dx * dx + dy * dy) < minArea)
                            
                                minArea = i * times * (dx * dx + dy * dy);
                                
                            
                            break;
                        }
                    }
                    if (isEnd)
                        break;
                    i++;
                }
            }
        }
        if (minArea == 1600000001)
            return 0;
        return minArea;
    }

  private:
    set<pair<int, int>> pointSet;
};

int main()
{
    Solution solve;
    vector<vector<int>> a{{2, 4}, {4, 2}, {1, 0}, {3, 4}, {4, 4}, {2, 2}, {1, 1}, {3, 0}, {1, 4}, {0, 3}, {0, 1}, {2, 1}, {4, 0}};
    //vector<vector<int>> a{{1, 2}, {0, 3}, {3, 1}, {2, 1}, {1, 3}};

    //cout << 1 << endl;
    cout << solve.minAreaFreeRect(a) << endl;
    system("pause");
    return 0;
}

/*
Note:
In the leetcode, this approach exceeded time limit. I think a better solution is that whenever a pair of points is reached, mark it
and this will reduce the number of loop. 
*/