#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class TimeMap
{
  public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        (timeMap[key]).push_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp)
    {
        for (auto it = timeMap[key].rbegin(); it != timeMap[key].rend(); it++)
        {
            if (it->first<=timestamp)
                return it->second;
        }
        return "";
    }

  private:
    map<string, vector<pair<int, string>>> timeMap;
};

int main()
{
    system("pause");
    return 0;
}