#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
		vector<int> ans;
		vector<int> rating;
		for (int i = 0; i < restaurants.size(); i++)
		{
			if ((veganFriendly && !restaurants[i][2]))
				continue;
			if (restaurants[i][3] > maxPrice)
				continue;
			if (restaurants[i][4] > maxDistance)
				continue;

			ans.push_back(restaurants[i][0]);
			rating.push_back(restaurants[i][1]);
		}
		if (ans.size() == 0)
			return ans;
		for (int i = 0; i < ans.size() - 1; i++)
		{
			for (int j = i; j < ans.size(); j++) {
				
				if (rating[i] < rating[j] || (rating[i] == rating[j] && ans[i] < ans[j])) {
					int tmp = ans[i];
					ans[i] = ans[j];
					ans[j] = tmp;

					tmp = rating[i];
					rating[i] = rating[j];
					rating[j] = tmp;
				}
			}
		}

		return ans;
	}
};

int main() {
	vector<vector<int>> restaurants = {{2817, 54550, 0, 24368, 82491}, {94849, 38849, 0, 97406, 43608}, {94567, 93218, 1, 66548, 87859}, {24884, 39764, 1, 77016, 65453}, {66229, 51558, 0, 62945, 31817}};
	Solution so;
	vector<int> ans = so.filterRestaurants(restaurants, 1, 54305, 87130);
	for (auto a : ans)
		cout << a << endl;
	system("pause");
}