#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution
{
  public:
    int shortestBridge(vector<vector<int>> &A)
    {
        int size = A.size();
        vector<vector<int>> island(size, vector<int>(size, 0));

        int num = 0;
        int x, y;
        while (true) //find the position of the first island
        {
            x = num / size;
            y = num % size;
            if (A[x][y] == 1)
                break;
            num++;
        }

        queue<pair<int, int>> Q;
        Q.push(make_pair(x, y));
        A[x][y] = 0;
        while (!Q.empty()) //BFS: determine the range of the first position
        {
            pair<int, int> cnt = Q.front();
            island[cnt.first][cnt.second] = 1;
            if (cnt.second < size - 1 && A[cnt.first][cnt.second + 1] == 1)
            {
                Q.push(make_pair(cnt.first, cnt.second + 1));
                A[cnt.first][cnt.second + 1] = 0;
            }
            if (cnt.first < size - 1 && A[cnt.first + 1][cnt.second] == 1)
            {
                Q.push(make_pair(cnt.first + 1, cnt.second));
                A[cnt.first + 1][cnt.second] = 0;
            }
            if (cnt.second > 0 && A[cnt.first][cnt.second - 1] == 1)
            {
                Q.push(make_pair(cnt.first, cnt.second - 1));
                A[cnt.first][cnt.second - 1] = 0;
            }
            if (cnt.first > 0 && A[cnt.first - 1][cnt.second] == 1)
            {
                Q.push(make_pair(cnt.first - 1, cnt.second));
                A[cnt.first - 1][cnt.second] = 0;
            }
            Q.pop();
        }

        while (true) //find the position of the second island
        {
            x = num / size;
            y = num % size;
            if (A[x][y] == 1)
                break;
            num++;
        }

        Q.push(make_pair(x, y));
        A[x][y] = 0;
        while (!Q.empty()) //BFS: determine the range of the second position
        {
            pair<int, int> cnt = Q.front();
            island[cnt.first][cnt.second] = 2;
            if (cnt.second < size - 1 && A[cnt.first][cnt.second + 1] == 1)
            {
                Q.push(make_pair(cnt.first, cnt.second + 1));
                A[cnt.first][cnt.second + 1] = 0;
            }
            if (cnt.first < size - 1 && A[cnt.first + 1][cnt.second] == 1)
            {
                Q.push(make_pair(cnt.first + 1, cnt.second));
                A[cnt.first + 1][cnt.second] = 0;
            }
            if (cnt.second > 0 && A[cnt.first][cnt.second - 1] == 1)
            {
                Q.push(make_pair(cnt.first, cnt.second - 1));
                A[cnt.first][cnt.second - 1] = 0;
            }
            if (cnt.first > 0 && A[cnt.first - 1][cnt.second] == 1)
            {
                Q.push(make_pair(cnt.first - 1, cnt.second));
                A[cnt.first - 1][cnt.second] = 0;
            }
            Q.pop();
        }

        Q.push(make_pair(x, y)); //determine the distance of each point from the second island
        while (!Q.empty())
        {
            pair<int, int> cnt = Q.front();

            if (cnt.second < size - 1)
            {
                if (island[cnt.first][cnt.second + 1] == 2)
                {
                    island[cnt.first][cnt.second + 1] = 3;
                    Q.push(make_pair(cnt.first, cnt.second + 1));
                }
                else if (island[cnt.first][cnt.second + 1]<2&&(A[cnt.first][cnt.second + 1] == 0 || A[cnt.first][cnt.second] + 1 < A[cnt.first][cnt.second + 1]))
                {
                    A[cnt.first][cnt.second + 1] = A[cnt.first][cnt.second] + 1;
                    Q.push(make_pair(cnt.first, cnt.second + 1));
                }
            }
            if (cnt.first < size - 1)
            {
                if (island[cnt.first + 1][cnt.second] == 2)
                {
                    island[cnt.first + 1][cnt.second] = 3;
                    Q.push(make_pair(cnt.first + 1, cnt.second));
                }
                else if (island[cnt.first + 1][cnt.second]<2&&(A[cnt.first + 1][cnt.second] == 0 || A[cnt.first][cnt.second] + 1 < A[cnt.first + 1][cnt.second]))
                {
                    A[cnt.first + 1][cnt.second] = A[cnt.first][cnt.second] + 1;
                    Q.push(make_pair(cnt.first + 1, cnt.second));
                }
            }
            if (cnt.second > 0)
            {
                if (island[cnt.first][cnt.second - 1] == 2)
                {
                    island[cnt.first][cnt.second - 1] = 3;

                    Q.push(make_pair(cnt.first, cnt.second - 1));
                }
                else if (island[cnt.first][cnt.second - 1]<2&&(A[cnt.first][cnt.second - 1] == 0 || A[cnt.first][cnt.second] + 1 < A[cnt.first][cnt.second - 1]))
                {
                    A[cnt.first][cnt.second - 1] = A[cnt.first][cnt.second] + 1;
                    Q.push(make_pair(cnt.first, cnt.second - 1));
                }
            }
            if (cnt.first > 0)
            {
                if (island[cnt.first - 1][cnt.second] == 2)
                {
                    island[cnt.first - 1][cnt.second] = 3;

                    Q.push(make_pair(cnt.first - 1, cnt.second));
                }
                else if (island[cnt.first - 1][cnt.second] <2 &&(A[cnt.first - 1][cnt.second] == 0 || A[cnt.first][cnt.second] + 1 < A[cnt.first - 1][cnt.second]))
                {
                    A[cnt.first - 1][cnt.second] = A[cnt.first][cnt.second] + 1;
                    Q.push(make_pair(cnt.first - 1, cnt.second));
                }
            }
            Q.pop();
        }

        int distance = 300;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (island[i][j] == 1 && A[i][j] < distance)
                    distance = A[i][j];
        return distance - 1;
    }
};

int main()
{
    Solution solve;
    vector<vector<int>> A{{0, 1, 0, 0, 0}, {0, 1, 0, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    int ans = solve.shortestBridge(A);
    cout << ans << endl;
    system("pause");
    return 0;
}