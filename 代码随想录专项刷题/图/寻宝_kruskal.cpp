# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

struct Edge {
    int l, r, val;
};

int n = 10001;
vector<int> father(n, -1);

void init () {
    for (int i = 0; i < n; ++ i )
        father[i] = i;
    return ;
}

int find (int u) {
    return u == father[u] ? u : father[u] = find(father[u]);
}

bool isSame (int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

void merge (int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return ;
    father[v] = u;
    return ;
}

int main () {
    int v, e;
    int v1, v2, val;
    vector<Edge> edges;
    int result_val = 0;
    cin >> v >> e;
    while (e --) {
        cin >> v1 >> v2 >> val;
        edges.push_back({v1, v2, val});
    }
    
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.val < b.val;
    });
    
    init();
    
    for (const Edge& edge : edges) {
        int x = find(edge.l);
        int y = find(edge.r);

        if (x != y) {
            result_val += edge.val;
            merge(x, y);
        }
    }
    
    cout << result_val << endl;
    return 0;
}