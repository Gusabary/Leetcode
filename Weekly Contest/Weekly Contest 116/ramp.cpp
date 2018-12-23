#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int maxWidthRamp(vector<int> &A)
    {
        int maxLen;
        if (trick(A, maxLen))
            return maxLen - 1;
        maxLen = 0;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = A.size() - 1; j > i; j--)
            {
                if (A[j] >= A[i] && j - i > maxLen)
                {
                    maxLen = j - i;
                    break;
                }
                if (j - i == maxLen)
                    break;
            }
            if (A.size() - 1 - i == maxLen)
                break;
        }
        return maxLen;
    }

  private:
    bool trick(vector<int> A, int &maxLen)
    {
        bool isInOrder = true;
        maxLen = 0;
        int len = 1;
        for (int i = 0; i < A.size() - 1; i++)
        {
            if (A[i + 1] > A[i])
            {
                isInOrder = false;
                return false;
            }
            if (A[i + 1] == A[i])
                len++;
            if (A[i + 1] < A[i])
            {

                len = 1;
            }
        }
        if (len > maxLen)
            maxLen = len;
        return true;
    }
};

int main()
{
    Solution solve;
    vector<int> a{1, 1, 1};
    cout << solve.maxWidthRamp(a) << endl;
    system("pause");
    return 0;
}