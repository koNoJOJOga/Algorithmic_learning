#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 原始结构体名称`road`不够直观，改为`Edge`，增加语义清晰度
struct Edge {
    int u, v, cost;
};

int n, k;
vector<int> enemyCities; // 用vector替代数组以支持动态调整
int parent[100002], Size[100002];
bool occupied[100002]; // 标记城市是否被敌军占领

// 原始cmp函数改为结构体内置比较操作符，提升代码结构一致性
bool cmp(const Edge &a, const Edge &b) {
    return a.cost > b.cost; // 修改为从大到小排序，便于构建最大生成树
}

// 并查集查找
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // 路径压缩
    }
    return parent[x];
}

// 并查集合并
void unionSets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (Size[a] < Size[b]) swap(a, b); // 保证较大集合合并较小集合
        parent[b] = a;
        Size[a] += Size[b];
    }
}

int main() {
    cin >> n >> k;

    // 敌军城市输入
    enemyCities.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> enemyCities[i];
        occupied[enemyCities[i]] = true; // 标记为敌军城市
    }

    // 边输入
    vector<Edge> edges(n - 1);
    long long totalCost = 0; // 总边权
    for (int i = 0; i < n - 1; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
        totalCost += edges[i].cost;
    }

    // 按边权从大到小排序
    sort(edges.begin(), edges.end(), cmp);

    // 初始化并查集
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        Size[i] = 1;
    }

    long long usedCost = 0;

    // 遍历所有边
    for (const auto &edge : edges) {
        int u = edge.u, v = edge.v;
        int rootU = find(u), rootV = find(v);

        // 如果两个城市属于不同集合且不能导致敌军城市互相连通
        if (rootU != rootV) {
            if (occupied[rootU] && occupied[rootV]) {
                continue; // 跳过会导致敌军连通的边
            }

            // 合并集合
            unionSets(u, v);
            int newRoot = find(u);

            // 更新新集合的敌军状态
            occupied[newRoot] = occupied[rootU] || occupied[rootV];

            // 累加当前边的代价
            usedCost += edge.cost;
        }
    }

    // 输出结果为总代价减去使用的代价
    cout << totalCost - usedCost << endl;

    return 0;
}
