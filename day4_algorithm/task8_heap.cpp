#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // 使用优先队列（最小堆）存储果子重量
    priority_queue<int, vector<int>, greater<int>> pq;

    // 读入果子重量并放入优先队列
    for (int i = 0; i < n; ++i) {
        int weight;
        cin >> weight;
        pq.push(weight);
    }

    int total_cost = 0;

    // 不断合并两堆最小的果子，直到只剩下一堆
    while (pq.size() > 1) {
        // 取出两堆最小重量的果子
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();

        // 合并这两堆果子，耗费体力为两者重量之和
        int cost = first + second;
        total_cost += cost;

        // 将合并后的新堆重量放回优先队列
        pq.push(cost);
    }

    // 输出总耗费的体力
    cout << total_cost << endl;

    return 0;
}
