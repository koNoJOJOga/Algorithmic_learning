#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> D(N);
    for (int i = 0; i < N; ++ i ) cin >> D[i];
    
    vector<int> C(M);
    for (int i = 0; i < M; ++ i ) cin >> C[i];
    
    vector<int> prev(M + 1, 1e9); // 初始化为足够大的值
    prev[0] = 0; // 初始状态：0次移动，0天
    
    for (int i = 1; i <= N; ++i) {
        vector<int> current(M + 1, 1e9);
        int current_min = 1e9;
        
        // 处理第i次移动，遍历可能的天数j（从i到M）
        for (int j = i; j <= M; ++j) {
            if (j - 1 >= 0) {
                current_min = min(current_min, prev[j - 1]);
            }
            current[j] = current_min + D[i - 1] * C[j - 1];
        }
        
        prev = move(current); // 使用move优化内存，避免复制
    }
    
    // 找出从N天到M天中的最小疲劳度
    int ans = *min_element(prev.begin() + N, prev.begin() + M + 1);
    cout << ans << endl;
    
    return 0;
}