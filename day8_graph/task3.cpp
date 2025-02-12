# include <iostream>
# include <vector>
# include <queue>
# include <cmath>
# include <iomanip>
# include <limits>
using namespace std;

struct Edge {
    int to;
    double cost;    // cost = -log(1 - z/100)
};

int main () {
    int n, m;
    cin >> n >> m;

    // 邻接表
    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; ++ i ) {
        int u, v, z;
        cin >> u >> v >> z;

        double factor = 1.0 - (z / 100.0);
        double cost = -log(factor);

        graph[u].push_back({v, cost});
        graph[v].push_back({u, cost});
    }

    int A, B;
    cin >> A >> B;

    // dj
    vector<double> dist(n + 1, numeric_limits<double>::infinity());

    typedef pair<double, int> P;
    priority_queue<P, vector<P>, greater<P>> pq;

    dist[A] = 0.0;
    pq.push({0.0, A});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;

        for (const auto &edge : graph[u]){
            int v = edge.to;
            double newCost = d + edge.cost;
            if (newCost < dist[v]){
                dist[v] = newCost;
                pq.push({newCost, v});
            }
        }
    }
    
    // 最优路径的成本为 dist[B]，则最优路径上乘积 P = exp(-dist[B])
    // A 需要发送的金额 X = 100 / P = 100 * exp(dist[B])
    double answer = 100.0 * exp(dist[B]);
    
    // 输出答案，精确到小数点后 8 位
    cout << fixed << setprecision(8) << answer << "\n";
    return 0;
}