#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (d > jobDifficulty.size()) {
			return -1;
		}

		vector<vector<vector<int>>> f;
		f.reserve(jobDifficulty.size());
		for (int i = 0; i < jobDifficulty.size(); i++) {
			f.reserve(d);
		}

		f[0][0] = vector<int>(); 
		f[0][0].push_back(jobDifficulty[0]);
		f[0][0].push_back(jobDifficulty[0]);
		for (int i = 1; i < jobDifficulty.size(); i++)
		{
			if (f[i-1][0][0] < jobDifficulty[i]) {
				f[i][0].push_back(jobDifficulty[i]);
				f[i][0].push_back(jobDifficulty[i]);
			}
			else {
				f[i][0].push_back(f[i-1][0][0]);
				f[i][0].push_back(f[i-1][0][0]);
			}
		}

		for (int i = 1; i < d; i++) {
			f[i][i] = f[i - 1][i - 1];
			f[i][i][0] = f[i - 1][i - 1][0] + jobDifficulty[i];
			f[i][i].push_back(jobDifficulty[i]);
		}

		for (int i = 0; i < jobDifficulty.size(); i++)
		{
			for (int j = 0; j < d; j++) {
				cout << f[i][j][0] << ' ';
			}
			cout << endl;
		}
		return 0;
	}
};

int main() {
	vector<int> j = {7, 1, 7, 1, 7, 1};
	Solution so;
	so.minDifficulty(j, 3);
	system("pause");
	return 0;
}