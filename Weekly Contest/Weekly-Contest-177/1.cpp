#include <iostream>
#include <string>
#include <utility>
#include <set>
#include <cstdlib>

using namespace std;

class Solution {
public:
    set<int> smallMonth = {4, 6, 9, 11};
    set<int> bigMonth = {1, 3, 5, 7, 8, 10, 12};
    bool isLeapYear(int year) {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            return true;
        }
        return false;
    }

    int daysBetweenDates(string date1, string date2) {
        int y1 = atoi(date1.substr(0, 4).c_str());
        int m1 = atoi(date1.substr(5, 2).c_str());
        int d1 = atoi(date1.substr(8, 2).c_str());
        int y2 = atoi(date2.substr(0, 4).c_str());
        int m2 = atoi(date2.substr(5, 2).c_str());
        int d2 = atoi(date2.substr(8, 2).c_str());

        if (y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 > d2)) {
            swap(y1, y2);
            swap(m1, m2);
            swap(d1, d2);
        }

        int ans = 0;

        if (y1 < y2) {
            if (m1 == 2 && !isLeapYear(y1))
                ans += (28 - d1);
            else if (m1 == 2 && isLeapYear(y1))
                ans += (29 - d1);
            else if (smallMonth.find(m1) != smallMonth.end())
                ans += (30 - d1);
            else if (bigMonth.find(m1) != bigMonth.end())
                ans += (31 - d1);

            for (int m = m1 + 1; m <= 12; m++) {
                if (m == 2 && !isLeapYear(y1))
                    ans += 28;
                else if (m == 2 && isLeapYear(y1))
                    ans += 29;
                else if (smallMonth.find(m) != smallMonth.end())
                    ans += 30;
                else if (bigMonth.find(m) != bigMonth.end())
                    ans += 31;
            }

            for (int y = y1 + 1; y < y2; y++) {
                if (isLeapYear(y))
                    ans += 366;
                else
                    ans += 365;
            }

            for (int m = 1; m < m2; m++) {
                if (m == 2 && !isLeapYear(y2))
                    ans += 28;
                else if (m == 2 && isLeapYear(y2))
                    ans += 29;
                else if (smallMonth.find(m) != smallMonth.end())
                    ans += 30;
                else if (bigMonth.find(m) != bigMonth.end())
                    ans += 31;
            }

            ans += d2;
        }
        else if (m1 < m2) {
            if (m1 == 2 && !isLeapYear(y1))
                ans += (28 - d1);
            else if (m1 == 2 && isLeapYear(y1))
                ans += (29 - d1);
            else if (smallMonth.find(m1) != smallMonth.end())
                ans += (30 - d1);
            else if (bigMonth.find(m1) != bigMonth.end())
                ans += (31 - d1);

            for (int m = m1 + 1; m < m2; m++) {
                if (m == 2 && !isLeapYear(y1))
                    ans += 28;
                else if (m == 2 && isLeapYear(y1))
                    ans += 29;
                else if (smallMonth.find(m) != smallMonth.end())
                    ans += 30;
                else if (bigMonth.find(m) != bigMonth.end())
                    ans += 31;
            }

            ans += d2;
        }
        else {
            ans += (d2 - d1);
        }

        return ans;
    }
};