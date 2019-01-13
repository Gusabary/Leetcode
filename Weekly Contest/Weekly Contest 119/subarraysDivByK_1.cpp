#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
  public:
    int subarraysDivByK(vector<int> &A, int K)
    {
        int ans = 0;
        stack<stackET> S;
        stackET tmpET;
        tmpET.sum = 0;
        tmpET.data = A;
        tmpET.stats = 0;
        S.push(tmpET);
        while (!S.empty())
        {
            stackET cnt = S.top();

            /*cout << cnt.sum << "     ";
            for (int i = 0; i < cnt.data.size(); i++)
                cout << cnt.data[i] << ' ';
            cout << "     " << cnt.stats;
            cout << endl;*/

            S.pop();
            if (cnt.data.empty()||cnt.stats==2)
            {
                // cout << "  " << cnt.sum << endl;
                if (canBeDivided(K,cnt.sum))
                {
                    ans++;
                    //cout << "   " << cnt.sum << endl;
                }
            }
            else
            {
                int value = cnt.data[cnt.data.size() - 1];
                cnt.data.pop_back();

                stackET tmpET = cnt;

                if (cnt.stats != 2)
                {
                    if (cnt.stats == 1)
                        tmpET.stats = 2;
                    S.push(tmpET); //not take

                    tmpET.stats = 1;
                    tmpET.sum = cnt.sum + value;
                    S.push(tmpET); //take
                }
            }
        }
        return ans - 1;
    }

  private:
    struct stackET
    {
        int sum;
        vector<int> data;
        int stats;
    };
    bool canBeDivided(int divisor, int dividend)
    {
        if (divisor == 0)
            return true;
        if (dividend % divisor == 0)
            return true;
        return false;
    }
};

int main()
{
    Solution solve;
    vector<int> a{4, 5, 0, -2, -3, 1};
    cout << solve.subarraysDivByK(a, 5) << endl;
    system("pause");
    return 0;
}