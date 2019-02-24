#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int numRookCaptures(vector<vector<char>> &board)
    {
        int posX, posY;
        for (int i = 0; i < 64; i++)
            if (board[i / 8][i % 8] == 'R')
            {
                posX = i / 8;
                posY = i % 8;
                break;
            }
        int ans = 0;
        int x = posX, y = posY;
        while (x >= 0)
        {
            if (board[x][y] == 'p')
            {
                ans++;
                break;
            }
            if (board[x][y] == 'B')
                break;
            x--;
        }

        x = posX;
        y = posY;
        while (x <= 7)
        {
            if (board[x][y] == 'p')
            {
                ans++;
                break;
            }
            if (board[x][y] == 'B')
                break;
            x++;
        }

        x = posX;
        y = posY;
        while (y >= 0)
        {
            if (board[x][y] == 'p')
            {
                ans++;
                break;
            }
            if (board[x][y] == 'B')
                break;
            y--;
        }

        x = posX;
        y = posY;
        while (y<=7)
        {
            if (board[x][y] == 'p')
            {
                ans++;
                break;
            }
            if (board[x][y] == 'B')
                break;
            y++;
        }

        return ans;
    }
};
