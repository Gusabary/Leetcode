#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        vector<string> ans;
        for (auto i = queries.begin(); i != queries.end(); i++)
        {
            bool flag = false;
            for (auto it = wordlist.begin(); it != wordlist.end(); it++)
                if (*it == *i)
                {
                    ans.push_back(*it);
                    flag = true;
                    break;
                }
            if (!flag)
                for (auto it = wordlist.begin(); it != wordlist.end(); it++)
                {
                    bool isCorrect = true;
                    if (it->size() != i->size())
                        break;
                    for (int j = 0; j < it->size(); j++)
                        if ((*it)[j] != (*i)[j] && abs((*it)[j] - (*i)[j]) != 32)
                        {
                            isCorrect = false;
                            break;
                        }
                    if (isCorrect)
                    {
                        ans.push_back(*it);
                        flag = true;
                        break;
                    }
                }
            if (!flag)
                for (auto it = wordlist.begin(); it != wordlist.end(); it++)
                {
                    bool isCorrect = true;
                    if (it->size() != i->size())
                        break;
                    for (int j = 0; j < it->size(); j++)
                        if ((*it)[j] != (*i)[j] && (isfu((*it)[j]) || isfu((*i)[j]))&& abs((*it)[j] - (*i)[j]) != 32)
                        {
                            isCorrect = false;
                            break;
                        }
                    if (isCorrect)
                    {
                        ans.push_back(*it);
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                    ans.push_back("");
        }
        return ans;
    }

  private:
    bool isfu(char ch)
    {
        if (ch == 'a' || ch == 'o' || ch == 'e' || ch == 'i' || ch == 'u')
            return false;
        return true;
    }
};

int main()
{
    Solution solve;
    vector<string> a = {"KiTe", "kite", "hare", "Hare"};
    vector<string> b = {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"};
    vector<string> c=solve.spellchecker(a, b);
    for (auto it = c.begin(); it != c.end();it++)
        cout << *it << endl;
        system("pause");
    return 0;
}