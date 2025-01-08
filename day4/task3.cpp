#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

int parent[MAXN], Size[MAXN];
bool active[MAXN];
vector<int> adj[MAXN];

int find(int x) 
{
    if (parent[x] != x) 
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (Size[a] < Size[b]) swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    // 输入图的边
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 输入关闭顺序
    vector<int> order(N);
    for (int i = 0; i < N; ++i) {
        cin >> order[i];
    }

    // 初始化并查集
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        Size[i] = 1;
        active[i] = false;
    }

    vector<string> result;
    int components = 0;

    // 按逆序恢复谷仓
    for (int i = N - 1; i >= 0; --i) {
        int barn = order[i];
        active[barn] = true;
        components++;

        // 将当前谷仓与其邻居连通
        for (int neighbor : adj[barn]) {
            if (active[neighbor] && find(barn) != find(neighbor)) {
                unionSets(barn, neighbor);
                components--;
            }
        }

        // 检查连通性
        if (components == 1) {
            result.push_back("YES");
        } else {
            result.push_back("NO");
        }
    }

    // 按顺序输出结果
    reverse(result.begin(), result.end());
    for (const string& res : result) {
        cout << res << endl;
    }

    return 0;
}