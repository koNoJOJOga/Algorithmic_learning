# include <iostream>
# include <vector>
# include <queue>
# include <climits>
using namespace std;

struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
    bool operator > (const Edge& other) const {
        return weight > other.weight;
    }
};

int main () {
    int v, e, x, y, k;
    cin >> v >> e;
    vector<vector<Edge>> adj(v + 1);
    while (e --) {
        cin >> x >> y >> k;
        adj[x].emplace_back(y, k);
        adj[y].emplace_back(x, k);
    }

    vector<int> minDist(v + 1, INT_MAX);
    vector<bool> isInTree(v + 1, false);
    priority_queue<Edge> pq;

    minDist[1] = 0;
    pq.push(Edge(1, 0));

    int ans = 0;
    while (!pq.empty()) {
        int cur = pq.top().to;
        int curWeight = pq.top().weight;
        pq.pop();

        if (isInTree[cur]) continue;
        isInTree[cur] = true;
        ans += curWeight;

        for (const auto& edge : adj[cur]) {
            int next = edge.to;
            int weight = edge.weight;
            if (!isInTree[next] && weight < minDist[next]) {
                minDist[next] = weight;
                pq.push(Edge(next, weight));
            }
        }
    }

    cout << ans << endl;
    return 0;
}