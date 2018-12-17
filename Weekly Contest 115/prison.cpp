#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int findLoop(const vector<int> &cells)
    {
        int period = 0;
        vector<vector<int>> status;
        status.push_back(cells);
        while (true)
        {
            vector<int> cntStatus(8);
            for (int i = 1; i <= 6; i++)
            {
                if (status[period][i - 1] == status[period][i + 1])
                    cntStatus[i] = 1;
                else
                    cntStatus[i] = 0;
            }
            cntStatus[0] = 0;
            cntStatus[7] = 0;
            status.push_back(cntStatus);
            period++;

            if (period >= 3 && status[period - 1] == status[1])
                break;
        }
        return period - 2;
    }
    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {
        int period = findLoop(cells);
        N = (N - 1) % period + 1; //mapping
        vector<int> v1(8), v2 = cells;
        vector<int> cntDayStatus(8), lastDayStatus = cells;
        cntDayStatus[0] = 0;
        cntDayStatus[7] = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= 6; j++)
            {
                if (lastDayStatus[j - 1] == lastDayStatus[j + 1])
                    cntDayStatus[j] = 1;
                else
                    cntDayStatus[j] = 0;
            }
            lastDayStatus = cntDayStatus; //go to the next day
        }
        return cntDayStatus;
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