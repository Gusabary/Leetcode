#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
		vector<int> ans;
		for (int i = 0; i < n; i++)
		{
			vector<int> dis;
			dis.resize(n);
			for (int j = 0; j < n; j++)
				dis[j] = -1;
			dis[i] = 0;

			for (int count = 0; count < n-1; count++) {
				int node;
				int tmpdis = -1;
				for (int j = 0; j < edges.size(); j++) {
					if (dis[edges[j][0]] * dis[edges[j][1]] > 0)
						continue;
					if (dis[edges[j][0]] == 0 && dis[edges[j][1]] > 0)
						continue;
					if (dis[edges[j][1]] == 0 && dis[edges[j][0]] > 0)
						continue;
					if (dis[edges[j][0]] >= 0) {
						if (dis[edges[j][0]] + edges[j][2] < tmpdis || tmpdis < 0) {
							tmpdis = dis[edges[j][0]] + edges[j][2];
							node = edges[j][1];
						}
					}
					else {
						if (dis[edges[j][1]] + edges[j][2] < tmpdis || tmpdis < 0) {
							tmpdis = dis[edges[j][1]] + edges[j][2];
							node = edges[j][0];
						}
					}
				}
				dis[node] = tmpdis;
			}

			int ansCount = 0;
			for (int j = 0; j < n; j++)
			{
				if (dis[j] > 0 && dis[j] <= distanceThreshold)
					ansCount++;
			}
			ans.push_back(ansCount);

			for (int j = 0; j < n; j++) {
				cout << dis[j] << ' ';
			}
			cout << endl;
		}

		int id;
		int min = -1;
		for (int i = 0; i < n; i++)
		{
			if (min < 0 || ans[i] <= min) {
				min = ans[i];
				id = i;
			}
			//cout << ans[i] << ' ';
		}
		// cout << endl;
		return id;
	}
};

int main() {
	vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
	Solution so;
	int ans = so.findTheCity(4, edges, 4);
	cout << ans << endl;
	system("pause");
}