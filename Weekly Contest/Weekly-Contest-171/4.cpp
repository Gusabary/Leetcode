class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<int>> f;
        f.resize(n+1);
        for (int i = 0; i <= n; i++) {
            f[i].resize(n+1);
            for (int j = 0; j<=n;j++)
                f[i][j] = -1;
        }
        f[0][1] = 0;
        f[1][0] = 0;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= i - 2; j++) {
                f[j][i] = f[j][i - 1] + distance(i - 1, i, word);
            }

            for (int j = 0; j <= i - 2; j++) {
                if (f[i - 1][j] + distance(j, i, word) < f[i - 1][i] || f[i - 1][i] == -1)
                    f[i - 1][i] = f[i - 1][j] + distance(j, i, word);
            }

            for (int j = 0; j <= i - 1; j++) {
                f[i][j] = f[j][i];
            }
        }

        int ans = -1;
        for (int i = 0; i <= n - 1; i++) {
            if (f[i][n] < ans || ans == -1)
                ans = f[i][n];
        }
        
        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= n; j++)
        //         cout << f[i][j] << ' ';
        //     cout << endl;
        // }
        return ans;
    }

    int distance(const int i, const int j, const string &word) {
         if (i == 0 || j == 0)
             return 0;
        int dis = abs(word[i-1] - word[j-1]);
        int dx = dis % 6;
        int dy = dis / 6;
        int max = 0;
        int min = 0;
        if (word[i-1]>word[j-1]) {
            max = word[i-1] - 'A';
            min = word[j-1] - 'A';
        }
        else {
            max = word[j-1] - 'A';
            min = word[i-1] - 'A';
        }
        if (max % 6 < min % 6) {
            dx = 6 - dx;
            dy++;
        }
        return dx + dy;
    }
};