#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<vector<int>> result;
vector<int> path;

void dfs (const vector<list<int>>& g, int x, int n) {

    if (x == n) {
        result.push_back(path);
        return;
    }
    
    for (int i : g[x]) {
        path.push_back(i);
        dfs (g, i, n);
        path.pop_back();
    }
}

int main () {
    int n, m, s, t;
    cin >> n >> m;

    vector<list<int>> g(n + 1);
    while (m--) {
        cin >> s >> t;
        g[s].push_back(t);
    }
    
    path.push_back(1);
    dfs(g, 1, n);
    
    // output
    if (result.size() == 0) cout << -1 << endl;
    for (const vector<int> &pa : result) {
        for (int i = 0; i < pa.size() - 1; ++ i ) {
            cout << pa[i] << " ";
        }
            
        cout << pa[pa.size() - 1] << endl;
    }
    
    return 0;
}