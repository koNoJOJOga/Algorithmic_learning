# include <iostream>
# include <vector>
using namespace std;

int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int ans;
void dfs (vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited) {
    visited[x][y] = true;
    for (int i = 0; i < 4; ++ i ) {
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) {
            ++ ans;
            continue;
        }
        if (grid[next_x][next_y] == 0) {    // ocean
            ++ ans;
            continue;
        } 
        else {
            if (visited[next_x][next_y])
                continue;
            dfs(grid, next_x, next_y, visited);
        }
    }
    
    return ;
}

int main () {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++ i )
        for (int j = 0; j < m; ++ j )
            cin >> grid[i][j];
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; ++ i ) 
        for (int j = 0; j < m; ++ j )
            if (grid[i][j] == 1 && !visited[i][j])
                dfs(grid, i, j, visited);
                
    cout << ans << endl;
    return 0;
}