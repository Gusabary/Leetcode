#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        const int size = events.size();
        sort(events.begin(), events.end(), comp);
        // quickSort(events);
        
        for (int i = 0; i < events.size(); i++)
            cout << events[i][0] << ' ' <<events[i][1] << endl;

        const int lastday = events.back()[1];
        int today = 1;
        int num = 0;
        while (today <= lastday && !events.empty()) {
            
            // cout << "----------today: " << today << "------num: " << num << endl;
            // for (int i = 0; i < events.size(); i++)
                // cout << events[i][0] << ' ' <<events[i][1] << endl;
            
            for (int i = 0; i < events.size(); i++) {
                if (events[i][1] >= today) {
                    break;
                }
                events.erase(events.begin() + i);
            }
            for (int i = 0; i < events.size(); i++) {
                if (events[i][0] <= today && events[i][1] >= today) {
                    num++;
                    events.erase(events.begin() + i);
                    break;
                }
            }
            today++;
        }
        return num;
    }

    static bool comp(vector<int> i, vector<int> j) {
        return (i[1] <= j[1]);
    }

    static void quickSort(std::vector<vector<int>> &array) {

        subQuickSort(array, 0, array.size() - 1);

    }

    static void subQuickSort(std::vector<vector<int>> &array, const int start, const int end) {
        if (start >= end)
            return;
        vector<int> stub = array[start];
        int left = start;
        int right = end;
        while (left < right) {
            while (left < right && array[right][1] >= stub[1]) {
                right--;
            }
            array[left] = array[right];
            while (left < right && array[left][1] <= stub[1]) {
                left++;
            }
            array[right] = array[left];
        }
        array[left] = stub;
        subQuickSort(array, start, left - 1);
        subQuickSort(array, right + 1, end);
    }
};
int main() {
    Solution s;
    vector<vector<int>> v = {{1, 1}, {26, 27}, {17, 17}, {1, 2}, {4, 7}, {16, 16}, {20, 23}, {8, 9}, {17, 19}, {4, 4}, {15, 15}, {23, 27}, {28, 31}, {25, 26}, {25, 29}, {30, 33}};
    int ans = s.maxEvents(v);
    system("pause");
    return 0;
}

// int main() {
//     vector<vector<int>> v = {{1, 1}, {26, 27}, {17, 17}, {1, 2}, {4, 7}, {16, 16}, {20, 23}, {8, 9}, {17, 19}, {4, 4}, {15, 15}, {23, 27}, {28, 31}, {25, 26}, {25, 29}, {30, 33}};
//     // sort(v.begin(), v.end(), comp);   
//     // for (int i = 0; i < v.size(); i++) {
//         // cout << v[i][0] << ' ' << v[i][1] << endl;
//     // }
//     system("pause");
//     return 0;
// }