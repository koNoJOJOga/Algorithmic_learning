#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<string> strings(n + 1); // 下标从 1 开始
    for (int i = 1; i <= n; ++i) {
        cin >> strings[i];
    }

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x, y, i;
            cin >> x >> y >> i;

            // 插入操作：将 strings[x] 插入到 strings[y] 的第 i 个字符后
            strings[y].insert(i, strings[x]);
        } else if (op == 2) {
            int y;
            cin >> y;

            // 输出操作：输出 strings[y]
            cout << strings[y] << endl;
        }
    }

    return 0;
}
