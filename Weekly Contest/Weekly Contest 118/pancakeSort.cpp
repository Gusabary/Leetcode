#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> pancakeSort(vector<int> &A)
    {
        for (int i = 1; i < A.size(); i++)
        {
            //cout << A[0] << ' ' << A[1] << ' ' << A[2] << endl;
            if (A[i] < A[i - 1])
            {
                int pos = i - 1;
                while (true)
                {
                    if (pos == -1 || A[pos] < A[i])
                        break;
                    pos--;
                }
                if (pos == -1)
                {
                    reverse(A, i);
                    reverse(A, i + 1);
                    continue;
                }
                reverse(A, i + 1);
                reverse(A, i - pos);
                reverse(A, i - pos - 1);
                reverse(A, i + 1);
            }
        }
        return ans;
    }

  private:
    vector<int> ans;
    void reverse(vector<int> &A, int x)
    {
        vector<int> tmp(105);
        for (int i = 0; i < x; i++)
            tmp[x - i-1] = A[i];
        for (int i = 0; i < x; i++)
            A[i] = tmp[i];
        ans.push_back(x);
    }
};

int main()
{
    Solution solve;
    vector<int> a;
    vector<int> b = {3,1,2};
    a = solve.pancakeSort(b);
    for (auto it = a.begin(); it != a.end(); it++)
        cout << *it << ' ';
    cout << endl;
    system("pause");
    return 0;
}