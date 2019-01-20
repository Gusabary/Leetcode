#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> sortedSquares(vector<int> &A)
    {
        vector<int> ans(A.size());
        for (int i = 0; i < A.size(); i++)
            ans[i] = A[i] * A[i];
        for (int i = 0; i < ans.size() - 1; i++)
            for (int j = i + 1; j < A.size(); j++)
            {
                if (ans[i] > ans[j])
                {
                    int tmp = ans[i];
                    ans[i] = ans[j];
                    ans[j] = tmp;
                }
            }
        return ans;
    }
};

int main()
{
    Solution solve;
    vector<int> a{-1, 1};
    vector<int> b = solve.sortedSquares(a);
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << ' ';
    cout << endl;
    system("pause");
    return 0;
}