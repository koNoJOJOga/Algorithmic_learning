# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

class UnionFind {
    public:
        vector<int> parent;

        UnionFind (int n) : parent (n + 1) {
            for (int i = 0; i <= n; ++ i )
                parent[i] = i;
        }

        int find (int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }

        void unionSet (int x, int y) {
            int fx = find (x);
            int fy = find (y);
            if (fx != fy) parent[fy] = fx;
        }
};

int main () {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++ i )
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort (edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {return a.w < b.w;});

    UnionFind uf(n);

    int ans = 0;

    for (const auto &e: edges) {
        uf.unionSet(e.u, e.v);

        if (uf.find(s) == uf.find(t)) {
            ans = e.w;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}