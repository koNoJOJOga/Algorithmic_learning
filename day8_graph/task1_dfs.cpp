# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

const long long INF = 2147483647LL;

// 1-based numbering
vector<int> w;   // weight
vector<int> sub;    // subpopulation sum
vector<long long> f;  // With the node as the root, the sum weight path to other nodes
vector<vector <int>> adj;   // stored in the adjacency tables

void dfs (int u, int fa, int dep) {
    sub[u] = w[u];
    f[1] += (long long) w[u] * dep; // the first layer will not be recorded bec the dep is 0

    for (int v: adj[u]) {
        if (v == fa) continue;

        dfs (v, u, dep + 1);
        sub[u] += sub[v];   // gets the weights of the subtree nodes and sums them up
    }
}

// equation of state transition: f[v] = f[u] + sub[1] - 2 * sub[v];
void dp (int u, int fa) {
    for (int v: adj[u]) {
        if (v == fa) continue;

        f[v] = f[u] + (sub[1] - 2 * sub[v]);
        dp (v, u);
    }
}

int main () {
    int n;
    cin >> n;

    // initialize
    w.resize(n + 1);
    sub.resize(n + 1, 0);
    f.resize(n + 1, 0);
    adj.resize(n + 1);

    // a large enough number
    long long ans = INF * INF;

    int a, b;
    for (int i = 1; i <= n; ++ i ) {
        cin >> w[i] >> a >> b;
        if (a != 0) {
            adj[i].push_back(a);
            adj[a].push_back(i);
        }
        if (b != 0) {
            adj[i].push_back(b);
            adj[b].push_back(i);
        }
    }

    // dfs 
    dfs(1, 0, 0);

    // dp
    dp(1, 0);

    for (int i = 1; i <= n; ++ i ) ans = min (ans, f[i]);

    cout << ans << endl;
    return 0;
}