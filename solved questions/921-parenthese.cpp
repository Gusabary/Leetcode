#include <iostream>

using namespace std;

class Solution
{
  public:
    int minAddToMakeValid(string S)
    {
        bool isNextToLeftParenthese = false;
        int numOfRightParenthese = 0;
        int numOfAllParenthese = 0;
        for (auto it = S.begin(); it != S.end(); it++)
        {
            if (*it == '(')
            {
                numOfAllParenthese++;
                isNextToLeftParenthese = true;
                continue;
            }
            if (isNextToLeftParenthese)
            {
                numOfAllParenthese--;
                if (numOfAllParenthese == numOfRightParenthese)
                    isNextToLeftParenthese = false;
                else
                    isNextToLeftParenthese = true;
            }
            else
            {
                numOfAllParenthese++;
                numOfRightParenthese++;
            }
        }
        return numOfAllParenthese;
    }
};

int main()
{
    string s;
    while (true)
    {
        cin >> s;
        Solution solve;
        int ans = solve.minAddToMakeValid(s);
        cout << ans << endl;
    }
    system("pause");
    return 0;
}