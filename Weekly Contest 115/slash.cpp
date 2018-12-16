#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int regionsBySlashes(vector<string> &grid)
    {
        vector<vector<bool>> point(grid.size() + 1, vector<bool>(grid.size() + 1));
        for (int i = 0; i < point.size(); i++)
        {
            point[i][0] = true;
            point[i][point.size() - 1] = true;
            point[0][i] = true;
            point[point.size() - 1][i] = true;
        }
        int num = 1;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '\\')
                {
                    if (point[i][j] && point[i + 1][j + 1])
                        num++;
                    else
                    {
                        point[i][j] = true;
                        point[i + 1][j + 1] = true;
                    }
                }
                if (grid[i][j] == '/')
                {
                    if (point[i + 1][j] && point[i][j + 1])
                        num++;
                    else
                    {
                        point[i+1][j] = true;
                        point[i][j + 1] = true;
                    }
                }
            }
        }
        return num;
    }
};

int main()
{

    system("pause");
    return 0;
}