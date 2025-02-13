# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int cnt;
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

void dfs (vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    for (int i = 0; i < 4; ++ i ) {
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size())
            continue;
        if (!visited[next_x][next_y] && grid[next_x][next_y] == 1) {
            visited[next_x][next_y] = true;
            ++ cnt;
            dfs(grid, visited, next_x, next_y);
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
            
    int result = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++ i ) 
        for (int j = 0; j < m; ++ j )
            if (!visited[i][j] && grid[i][j] == 1) {
                cnt = 1;
                visited[i][j] = true;
                dfs(grid, visited, i, j);
                result = max(result, cnt);
            }
            
    cout << result << endl;
    
    return 0;
}