#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    string strWithout3a3b(int A, int B)
    {
        string ans;
        if (A > B)
        {
            int n = A - B;
            if (n < B)
            {
                for (int i = 1; i <= n; i++)
                    ans += "aab";
                for (int i = 1; i <= B - n; i++)
                    ans += "ab";
            }
            else
            {
                for (int i = 1; i <= B; i++)
                    ans += "aab";
                for (int i = 1; i <= A - 2 * B; i++)
                    ans += "a";
            }
        }
        else
        {
            int n = B - A;
            if (n < A)
            {
                for (int i = 1; i <= n; i++)
                    ans += "bba";
                for (int i = 1; i <= A - n; i++)
                    ans += "ba";
            }
            else
            {
                for (int i = 1; i <= A; i++)
                    ans += "bba";
                for (int i = 1; i <= B - 2 * A; i++)
                    ans += "b";
            }
        }
        return ans;
    }
};

int main()
{

    system("pause");
    return 0;
}