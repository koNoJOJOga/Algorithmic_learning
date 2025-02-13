#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result;
vector<int> path;

void dfs (int x, int n, vector<vector<int>>& g) {
    if (x == n) {
        result.push_back(path);
        return;
    }

    for (int i = 1; i <= n; ++ i ) {
        if (g[x][i] == 1) {
            path.push_back(i);
            dfs(i, n, g);
            path.pop_back();
        }
    }
    return;
}

int main () {
    int n, m, s, t;
    cin >> n >> m;

    vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));

    while (m -- ) {
        cin >> s >> t;
        g[s][t] = 1;
    }

    path.push_back(1);
    dfs (1, n, g);

    if (result.size() == 0) cout << -1 << endl;
    for (const vector<int> &pa : result) {
        for (int i = 0; i < pa.size() - 1; ++ i )
            cout << pa[i] << " ";
        cout << pa[pa.size() - 1] << endl;
    }
    return 0;
}