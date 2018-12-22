#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
  public:
    int threeSumMulti(vector<int> &A, int target)
    {
        for (auto it = A.begin(); it != A.end(); it++)
            Amap[*it]++;
        int ans = 0;
        for (auto it = Amap.begin(); it != Amap.end(); it++)
        {
            if (it->first * 3 > target)
                break;
            for (auto it2 = it; it2 != Amap.end(); it2++)
            {
                if (it->first + it2->first * 2 > target)
                    break;
                for (auto it3 = it2; it3 != Amap.end(); it3++)
                {
                    if (it->first + it2->first + it3->first > target)
                        break;
                    if (it->first + it2->first + it3->first == target)
                        ans += findEqual(it->first, it2->first, it3->first);
                }
            }
        }
        return ans;
    }

  private:
    map<int, int> Amap;
    const int modNum = 1000000007;

    int findEqual(int a1, int a2, int a3)
    {
        if (a2 == a1)
        {
            if (a3 == a2)
            {
                if (Amap[a1] < 3)
                    return 0;
                return C(Amap[a1], 3);
            }
            if (Amap[a1] < 2)
                return 0;
            return C(Amap[a1], 2) * Amap[a3];
        }
        if (a3 == a2)
        {
            if (Amap[a2] < 2)
                return 0;
            return Amap[a1] * C(Amap[a2], 2);
        }
        return Amap[a1] * Amap[a2] * Amap[a3];
    }
    int C(int n, int m)
    {
        long long num = 1, den = 1;
        for (int i = n; i >= n - m + 1; i--)
            num *= i;
        for (int i = 1; i <= m; i++)
            den *= i;
        return (num / den) % modNum;
    }
};

int main()
{
    Solution solve;
    vector<int> A = {1, 1, 2, 2, 2, 2};
    int target = 5;
    cout << solve.threeSumMulti(A, target) << endl;

    system("pause");
    return 0;
}