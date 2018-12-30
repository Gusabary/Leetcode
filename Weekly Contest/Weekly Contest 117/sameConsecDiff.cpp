#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
  public:
    vector<int> numsSameConsecDiff(int N, int K)
    {
        if (N == 1)
        {
            vector<int> ans = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            return ans;
        }
        //build tree
        vector<int> ans;
        node *root = new node;
        buildTree(root, N);
        for (int i = 1; i <= 9; i++)
        {
            routes.clear();
            traverse(root, N, K, i);
            for (auto it = routes.begin(); it != routes.end(); it++)
            {
                // int num = i * pow(10, N - 1);
                int num = i;
                for (int j = 1; j <= N - 1; j++)
                    num *= 10;

                int tmp = i;
                for (auto it2 = it->begin(); it2 != it->end(); it2++)
                {
                    tmp += (*it2) * K;
                    num += tmp * pow(10, N - (it2 - it->begin()) - 2);
                }
                ans.push_back(num);
                if (K == 0)
                    break;
            }
        }
        return ans;
    }

  private:
    struct node
    {
        node *left;
        node *right;
        node() : left(NULL), right(NULL) {}
    };
    vector<vector<int>> routes;
    vector<int> route;
    void buildTree(node *root, int N)
    {
        node *tmp = new node;
        /*if (root->left==NULL)
            cout << 1 << endl;*/
        root->left = tmp;
        if (N > 2)
            buildTree(root->left, N - 1);
        node *tmp1 = new node;
        root->right = tmp1;
        if (N > 2)
            buildTree(root->right, N - 1);
        return;
    }

    void traverse(node *root, int N, int K, int cnt)
    {
        if (root->left == NULL)
        {
            routes.push_back(route);
            route.pop_back();
            return;
        }
        if (cnt - K >= 0)
        {
            route.push_back(-1);
            traverse(root->left, N, K, cnt - K);
        }
        if (cnt + K <= 9)
        {
            route.push_back(1);
            traverse(root->right, N, K, cnt + K);
        }
        if (!route.empty())
            route.pop_back();
        return;
    }
};

int main()
{
    Solution solve;
    vector<int> a;
    a = solve.numsSameConsecDiff(4, 1);
    for (auto it = a.begin(); it != a.end(); it++)
        cout << *it << ' ';
    cout << endl;
    system("pause");
    return 0;
}