#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {
        int k = 0;
        vector<vector<int>> a;
        a.push_back(cells);
        while (true)
        {
            vector<int> tmp(8);
            for (int i = 1; i <= 6; i++)
            {
                if (a[k][i - 1] == a[k][i + 1])
                    tmp[i] = 1;
                else
                    tmp[i] = 0;
            }
            tmp[0] = 0;
            tmp[7] = 0;
            a.push_back(tmp);
            k++;

            if (k >= 3 && a[k - 1] == a[1])
                break;
        }
        N = (N - 1) % (k - 2) + 1;
        vector<int> v1(8), v2 = cells;
        v1[0] = 0;
        v1[7] = 0;
        for (int i = 1; i <= N; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 1; j <= 6; j++)
                {
                    if (v1[j - 1] == v1[j + 1])
                        v2[j] = 1;
                    else
                        v2[j] = 0;
                }
            }
            else
            {
                for (int j = 1; j <= 6; j++)
                {
                    if (v2[j - 1] == v2[j + 1])
                        v1[j] = 1;
                    else
                        v1[j] = 0;
                }
            }
            if (i == 1)
            {
                v2[0] = 0;
                v2[7] = 0;
            }
        }
        if (N % 2 == 0)
            return v2;
        return v1;
    }
};

int main()
{
    Solution solve;
    vector<int> input{0, 1, 0, 1, 1, 0, 0, 1};

    vector<int> output = solve.prisonAfterNDays(input, 7);
    for (int i = 0; i <= 7; i++)
        cout << output[i] << ' ';
    system("pause");
    return 0;
}