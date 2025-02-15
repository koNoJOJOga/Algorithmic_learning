# include <iostream>
# include <vector>
using namespace std;

int n, m;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    if (visited[x][y]) return;

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
            continue;
        if (grid[x][y] > grid[next_x][next_y])
            continue;

        dfs (grid, visited, next_x, next_y);
    }

    return ;
}

int main () {
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++ i ) 
        for (int j = 0; j < m; ++ j )
            cin >> grid[i][j];

    vector<vector<bool>> firstBorder(n, vector<bool>(m, false));
    vector<vector<bool>> secondBorder(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++ i ) {
        dfs (grid, firstBorder, i, 0);
        dfs (grid, secondBorder, i, m - 1);
    }

    for (int i = 0; i < m; ++ i ) {
        dfs (grid, firstBorder, 0, i);
        dfs (grid, secondBorder, m - 1, i);
    }

    for (int i = 0; i < n; ++ i )
        for (int j = 0; j < m; ++ j )
            if (firstBorder[i][j] && secondBorder[i][j])
                cout << i << " " << j << endl;

    return 0;
}