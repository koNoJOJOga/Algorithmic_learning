# include <iostream>
# include <vector>
using namespace std;

using P = pair<int, int>;
bool flag = true;
int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
void dfs (vector<vector<int>>& grid, vector<vector<P>>& visited, int x, int y) {
    if (flag) {
        for (int i = 0; i < 4; ++ i ) {
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];
            if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size())
                continue;
            if (visited[next_x][next_y].first == 1 || grid[next_x][next_y] < grid[x][y])
                continue;
            visited[next_x][next_y].first = 1;
            dfs(grid, visited, next_x, next_y);
        }
    }
    else {
        for (int i = 0; i < 4; ++ i ) {
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];
            if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size())
                continue;
            if (visited[next_x][next_y].second == 1 || grid[next_x][next_y] < grid[x][y])
                continue;
            visited[next_x][next_y].second = 1;
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
    
    vector<vector<P>> visited(n, vector<P>(m, {0, 0})); // first: one, second: two
    
    // the first group
    for (int i = 0; i < n; ++ i ) {
        visited[i][0].first = 1;
        dfs(grid, visited, i, 0);
    }
        
    for (int i = 0; i < m; ++ i ) {
        visited[0][i].first = 1;
        dfs(grid, visited, 0, i);
    }
            
    flag = false;
            
    // the second group
    for (int i = 0; i < n; ++ i ) {
        visited[i][m - 1].second = 1;
        dfs(grid, visited, i, m - 1);
    }
    for (int i = 0; i < m; ++ i ) {
        visited[n - 1][i].second = 1;
        dfs(grid, visited, n - 1, i);
    }
            
    for (int i = 0; i < n; ++ i )
        for (int j = 0; j < m; ++ j )
            if (visited[i][j].first == 1 && visited[i][j].second == 1)
                cout << i << " " << j << endl;
    
    return 0;
}