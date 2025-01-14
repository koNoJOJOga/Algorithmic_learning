#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 25;
int dp[MAXN][MAXN];
bool blocked[MAXN][MAXN]; // 标记不可达点

// 马的控制点
const int dx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
const int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};

int main() {
    int n, m, hx, hy;
    cin >> n >> m >> hx >> hy;

    // 初始化 blocked 数组
    memset(blocked, false, sizeof(blocked));

    // 标记马的位置及其控制点为不可达
    blocked[hx][hy] = true;
    for (int i = 0; i < 8; ++i) {
        int nx = hx + dx[i];
        int ny = hy + dy[i];
        if (nx >= 0 && ny >= 0 && nx <= n && ny <= m) {
            blocked[nx][ny] = true;
        }
    }

    // 初始化 dp 数组
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; // 起点初始化

    // 动态规划求解
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (blocked[i][j]) continue; // 不可达点跳过
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
        }
    }

    // 输出结果
    cout << dp[n][m] << endl;
    return 0;
}
