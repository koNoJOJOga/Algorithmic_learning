# include <iostream>
# include <vector>
# include <queue>
using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void bfs (vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    using pq = pair<int, int>;
    queue<pq> que;
    que.push({x, y});
    visited[x][y] = true;
    
    while(!que.empty()){
        pq cur = que.front();
        que.pop();
        int cur_x = cur.first;
        int cur_y = cur.second;
        for (int i = 0; i < 4; ++ i ) {
            int next_x = cur_x + dir[i][0];
            int next_y = cur_y + dir[i][1];
            if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size())
                continue;
            if (!visited[next_x][next_y] && grid[next_x][next_y] == 1) {
                que.push({next_x, next_y});
                visited[next_x][next_y] = true;
            }
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
    
    int ans = 0;
    
    for (int i = 0; i < n; ++ i ) 
        for (int j = 0; j < m; ++ j )
            if (!visited[i][j] && grid[i][j] == 1) {
                ++ ans;
                bfs(grid, visited, i, j);
            }
    
    cout << ans << endl;
    return 0;
}