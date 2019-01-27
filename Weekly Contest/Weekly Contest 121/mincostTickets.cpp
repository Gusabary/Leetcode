#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        cost.push_back(0);
        for (int i = 1; i < days[0]; i++)
            cost.push_back(0);
        cost.push_back(costs[0]);
        //cout << cost.size() << endl;
        for (int i = 1; i < days.size(); i++)
        {
            fill(days[i] - days[i - 1] - 1);
            //cout << cost.size() << endl;
            
            cost.push_back(min(cost[days[i - 1]] + costs[0], (days[i] > 7 ? cost[days[i] - 7] : 0) + costs[1], (days[i] > 30 ? cost[days[i] - 30] : 0) + costs[2]));
            //cout << cost[cost.size() - 1] << ' ';
            /*for (int i = 1; i <= cost.size()-1; i++)
                cout << cost[i] << ' ';
            cout << endl;*/
        }
        return cost[days[days.size() - 1]];
    }

    vector<int> cost;

  private:
    void fill(int len)
    {
        int stuff = cost[cost.size() - 1];
        for (int i = 1; i <= len; i++)
            cost.push_back(stuff);
        //cout << " stuff:" << stuff << " len:" << len << ' ';
    }
    int min(int a, int b, int c)
    {
        if (a < b && a < c)
            return a;
        if (b < c)
            return b;
        return c;
    }
};

int main()
{
    Solution solve;
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};
    cout<<solve.mincostTickets(days, costs);
    /*for (int i = 1; i <= 20; i++)
        cout << solve.cost[i] << ' ';*/
    cout << endl;
    system("pause");
    return 0;
}