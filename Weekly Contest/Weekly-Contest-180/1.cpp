class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        const int n = matrix.size();
        const int m = matrix[0].size();
        vector<int> row;
        vector<int> col;
        for (vector<int> v : matrix) {
            int min = 100001;
            row.push_back(-1);
            for (int i = 0; i < v.size(); i++) {
                if (v[i] < min) {
                    row.back() = i;
                    min = v[i];
                }
            }
        }
        
//         for (int a : row) {
//             cout << a << ' ';
//         }
//         cout << endl;

        for (int i = 0; i < m; i++) {
            int max = 0;
            col.push_back(-1);
            for (int j = 0; j < n; j++) {
                if (matrix[j][i] > max) {
                    col.back() = j;
                    max = matrix[j][i];
                }
            }
        }
        
        // for (int a : col) {
        //     cout << a << ' ';
        // }
        // cout << endl;

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (col[row[i]] == i) {
                ans.push_back(matrix[i][row[i]]);
            }
        }
        return ans;
    }
};