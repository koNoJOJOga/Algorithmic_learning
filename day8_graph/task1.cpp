#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定义一个较大的常数（原代码中 INF = 2147483647，用于初始化答案，后乘以自身得到一个足够大的值）
const long long INF = 2147483647LL;

// 全局变量（均采用 1‐based 编号，即结点编号从 1 到 n）
int n;  
vector<int> w;         // w[i]：第 i 个结点的人口数
vector<int> sub;       // sub[i]：以结点 i 为根的子树中所有结点的人口总和
vector<long long> f;   // f[i]：当医院建在结点 i 时，整个树中居民的距离和
vector<vector<int>> adj;  // 邻接表表示树结构，adj[i] 存储与结点 i 相连的所有结点

// dfs 预处理：计算以每个结点为根的子树人口和，以及计算以 1 号结点为医院时的总距离 f[1]。
// 参数 u 表示当前结点，fa 为父结点（防止往回走），dep 为当前结点相对于根（1 号结点）的深度。
void dfs(int u, int fa, int dep) {
    // 初始化当前结点 u 的子树人口为自身人口
    sub[u] = w[u];
    // 累加当前结点对 f[1] 的贡献：人口数 * 深度（注意：根的深度为 0，不贡献）
    f[1] += (long long)w[u] * dep;
    
    // 遍历结点 u 的所有相邻结点
    for (int v : adj[u]) {
        // 跳过父结点，防止重复遍历
        if (v == fa) continue;
        // 递归处理子结点 v，深度加 1
        dfs(v, u, dep + 1);
        // 累加子树 v 的人口到当前结点 u 的子树人口
        sub[u] += sub[v];
    }
}

// dp 递推（重根技巧）：
// 利用已知父结点 u 的 f 值计算子结点 v 的 f 值，公式：
//   f[v] = f[u] + (总人口 - 2 * sub[v])
// 其中，总人口为 sub[1]（因为 1 号结点为根时，其子树包含整棵树）。
void dp(int u, int fa) {
    for (int v : adj[u]) {
        if (v == fa) continue;
        // 根据公式计算 v 为根（医院设在 v）时的距离和
        f[v] = f[u] + (sub[1] - 2 * sub[v]);
        dp(v, u);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 读入结点数
    cin >> n;
    
    // 将各个全局向量调整为 n+1 大小（1-indexed）
    w.resize(n + 1);
    sub.resize(n + 1, 0);
    f.resize(n + 1, 0);
    adj.resize(n + 1);
    
    // 初始化答案为一个足够大的值（原代码中先将 ans 初始化为 INF，再 ans *= ans）
    long long ans = INF * INF;
    
    int a, b;
    // 读入每个结点的数据：人口数、左链接和右链接（若为 0 表示无该链接）
    for (int i = 1; i <= n; i++){
        cin >> w[i] >> a >> b;
        // 若 a 非 0，则表示结点 i 与结点 a 之间有边（无向树，双向添加）
        if (a != 0) {
            adj[i].push_back(a);
            adj[a].push_back(i);
        }
        // 同理，若 b 非 0，则结点 i 与结点 b 之间有边
        if (b != 0) {
            adj[i].push_back(b);
            adj[b].push_back(i);
        }
    }
    
    // 第一次 DFS：以 1 号结点作为根，计算整个树的子树人口 sub[] 和
    // 当医院设在 1 号结点时的距离和 f[1]
    dfs(1, 0, 0);
    
    // 第二次 DFS（重根）：利用 f[1] 推导出其它结点作为医院时的距离和 f[i]
    dp(1, 0);
    
    // 遍历所有结点，求出最小的距离和
    for (int i = 1; i <= n; i++){
        ans = min(ans, f[i]);
    }
    
    cout << ans << "\n";
    return 0;
}
