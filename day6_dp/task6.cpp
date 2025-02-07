#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        // 计算前缀和
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++ i ) prefix[i + 1] = prefix[i] + a[i];

        // 动态规划数组
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0)); // dp[i][j]表示区间[i,j]的先手最大得分
        vector<vector<int>> left_min(n + 2, vector<int>(n + 2, 0));
        vector<vector<int>> right_min(n + 2, vector<int>(n + 2, 0));

        for (int len = 1; len <= n; ++ len ) {
            for (int i = 0; i + len <= n; ++ i ) {
                int j = i + len - 1;
                int sum_ij = prefix[j + 1] - prefix[i];

                // 计算left_min[i][j]
                left_min[i][j] = min(dp[i + 1][j], (i + 1 <= j ? left_min[i + 1][j] : 0));
                // 计算right_min[i][j]
                right_min[i][j] = min(dp[i][j - 1], (i <= j - 1 ? right_min[i][j - 1] : 0));

                dp[i][j] = max(sum_ij - left_min[i][j], sum_ij - right_min[i][j]);
            }
        }

        cout << dp[0][n - 1] << endl;
    }
    return 0;
}