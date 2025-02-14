# include <iostream>
# include <vector>
using namespace std;

int dir[4][2] = {-1, 0, 0, -1, 0, 1, 1, 0};
int cnt;
void dfs (vector<vector<int>> grid, int x, int y) {
    grid[x][y] = 0;
    ++ cnt;

    for (int i = 0; i < 4; ++ i ) {
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];

        if (next_x < 0 || next_x > grid.size() || next_y < 0 || next_y > grid[0].size())
            continue;
        
        if (grid[next_x][next_y] == 0) continue;

        dfs (grid, next_x, next_y);
    }

    return ;
}

int main () {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    for(int i = 0; i < n; ++ i )
        for (int j = 0; j < m; ++j )
            cin >> grid[i][j];

    // 左右两边
    for (int i = 0; i < n; ++ i ) {
        if (grid[i][0] == 1) dfs(grid, i, 0);
        if (grid[i][m - 1] == 1) dfs(grid, i, m - 1);
    }
    // 上下两边
    for (int i = 0; i < m; ++ i ) {
        if (grid[0][i] == 1) dfs(grid, 0, i);
        if (grid[n - 1][i] == 1) dfs(grid, n - 1, i);
    }
    cnt = 0;

    return 0;
}