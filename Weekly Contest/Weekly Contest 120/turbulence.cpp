#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int maxTurbulenceSize(vector<int> &A)
    {
        if (A.size() == 1)
            return 1;
        int maxLen = 0;
        int pos = 1;
        while (pos < A.size() - 1)
        {
            int start = pos;
            while (pos < A.size() - 1 && (A[pos + 1] - A[pos]) * (A[pos] - A[pos - 1]) < 0)
            {
                pos++;
            }
            if (pos - start + 1 > maxLen)
                maxLen = pos - start + 1;
            pos++;
        }
        return maxLen;
    }
};

int main()
{
    system("pause");
    return 0;
}