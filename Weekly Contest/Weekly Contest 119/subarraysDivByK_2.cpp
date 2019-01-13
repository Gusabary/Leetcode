#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int subarraysDivByK(vector<int> &A, int K)
    {
        int ans = 0;
        for (int len = 1; len <= A.size(); len++)
        {
            int sum = 0;
            for (int i = 0; i < len; i++)
                sum += A[i]%K;
            if (canBeDivided(K, sum))
                ans++;
            if (len == A.size())
                break;
            for (int pos = len; pos < A.size(); pos++)
            {
                sum -= A[pos - len]%K;
                sum += A[pos]%K;
                if (canBeDivided(K, sum))
                    ans++;
            }
        }
        return ans;
    }

  private:
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