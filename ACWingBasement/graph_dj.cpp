# include <iostream>
# include <vector> 
# include <queue>
# include <limits>
# include <functional>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

void Dijkstra (int n, int start, const vector<vector<Edge>>& graph) {
    vector<int> dist(n, INF);
    dist[start] = 0;

    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; ++ i ) {
        if (dist[i] == INF)
            cout << "INF ";
        else 
            cout << dist[i] << " ";
    }
    cout << endl;
}

int main () {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n);

    for (int i = 0; i < m; ++ i ) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int start;
    cin >> start;

    Dijkstra(n, start, graph);

    return 0;
}