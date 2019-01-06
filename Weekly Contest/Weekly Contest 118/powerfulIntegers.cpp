#include <iostream>
#include <vector>
#include <math.h>
#include <set>

using namespace std;

class Solution
{
  public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        int i = 0, j = 0;
        set<int> powerInt;
        while (true)
        {
            j = 0;
            if (pow(x, i) + pow(y, j) > bound)
                break;
            while (true)
            {
                if (pow(x, i) + pow(y, j) > bound)
                    break;
                powerInt.insert(pow(x, i) + pow(y, j));
                j++;
                if (y == 1)
                    break;
            }
            i++;
            if (x == 1)
                break;
        }
        vector<int> ans;
        for (auto it = powerInt.begin(); it != powerInt.end(); it++)
            ans.push_back(*it);
        return ans;
    }
};

int main()
{
    Solution solve;

    vector<int> a = solve.powerfulIntegers(3, 5, 15);
    for (auto it = a.begin(); it != a.end(); it++)
        cout << *it << ' ';
    cout << endl;
    system("pause");
    return 0;
}