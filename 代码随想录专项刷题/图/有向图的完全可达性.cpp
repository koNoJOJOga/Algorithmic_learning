# include <iostream>
# include <vector>
# include <queue>
# include <list>
using namespace std;

int main () {
    int n, k, from, to;
    cin >> n >> k;
    
    vector<list<int>> graph(n + 1);
    for (int i = 1; i <= k; ++ i ) {
        cin >> from >> to;
        graph[from].push_back(to);
    }
    
    vector<bool> visited(n + 1, false);
    queue<int> que;
    que.push(1);
    visited[1] = true;
    
    while (!que.empty()) {
        int node = que.front();
        que.pop();
        for (int i : graph[node]) {
            if (!visited[i]) {
                visited[i] = true;
                que.push(i);
            }
        }
    }
    
    for (int i = 1; i <= n; ++ i )
        if (!visited[i]) {
            cout << -1 << endl;
            return 0;
        }
    cout << 1 << endl;
    return 0;
}