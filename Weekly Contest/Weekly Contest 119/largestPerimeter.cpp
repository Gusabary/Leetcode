#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int largestPerimeter(vector<int> &A)
    {
        for (int i = 0; i < A.size() - 1; i++)
            for (int j = i + 1; j < A.size(); j++)
                if (A[i] < A[j])
                {
                    int tmp = A[i];
                    A[i] = A[j];
                    A[j] = tmp;
                }
        int ans = 0;
        for (int i = 0; i < A.size() - 2;i++)
        {
            if (A[i]<A[i+1]+A[i+2])
            {
                ans = A[i] + A[i + 1] + A[i + 2];
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solve;
    vector<int> a{2, 1, 1};
    cout << solve.largestPerimeter(a) << endl;

    system("pause");
    return 0;
}