#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int n, m;
int cnt;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void dfs (vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int mark) {
    visited[x][y] = true;
    grid[x][y] = mark;
    ++ cnt;
    for (int i = 0; i < 4; ++ i ) {
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size())
            continue;
        if (visited[next_x][next_y] || grid[next_x][next_y] != 1)
            continue;
        dfs(grid, visited, next_x, next_y, mark);
    }
    
    return ;
}

int main () {
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++ i )
        for (int j = 0; j < m; ++ j )
            cin >> grid[i][j];
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    unordered_map<int, int> gridNum;
    int mark = 2;
    bool isAllGrid = true;
    
    // map initialization
    for (int i = 0; i < n; ++ i )
        for (int j = 0; j < m; ++ j ) {
            if (grid[i][j] == 0)
                isAllGrid = false;
            if (!visited[i][j] && grid[i][j] == 1) {
                cnt = 0;
                dfs(grid, visited, i, j, mark);
                gridNum[mark] = cnt;
                ++ mark;
            }
        }
    
    if (isAllGrid) {
        cout << n * m << endl;
        return 0;
    }
    
    // Calculate the sum of the surrounding island areas based on the location of the added land
    int ans = 0;
    unordered_set<int> visitedGrid;
    for (int i = 0; i < n; ++ i )
        for (int j = 0; j < m; ++ j ) {
            cnt = 1;
            visitedGrid.clear();
            if (grid[i][j] == 0) 
                for (int k = 0; k < 4; ++ k ) {
                    int near_i = i + dir[k][0];
                    int near_j = j + dir[k][1];
                    if (near_i < 0 || near_i >= grid.size() || near_j < 0 || near_j >= grid[0].size())
                        continue;
                    if (visitedGrid.count(grid[near_i][near_j]))
                        continue;
                    cnt += gridNum[grid[near_i][near_j]];
                    visitedGrid.insert(grid[near_i][near_j]);
                }
            ans = max(ans, cnt);
        }
    cout << ans << endl;
    
    return 0;
}