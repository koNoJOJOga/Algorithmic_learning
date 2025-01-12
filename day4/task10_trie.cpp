#include <iostream>
#include <vector>
#include <array>

using namespace std;

struct Node {
    int cnt; 
    array<Node*, 62> ch{}; 

    Node() : cnt(0) {
        for (auto& ptr : ch) ptr = nullptr; 
    }

    void dfs() {
        for (auto ptr : ch) {
            if (ptr) {
                ptr->dfs();
                cnt += ptr->cnt;
            }
        }
    }
};

Node* rot;

int charToIndex(char c) {
    if ('a' <= c && c <= 'z') return c - 'a';       
    if ('A' <= c && c <= 'Z') return c - 'A' + 26;  
    return c - '0' + 52;                            
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n, q;
    string s;

    for (cin >> T; T; --T) {
        cin >> n >> q;

        rot = new Node(); // 初始化根节点

        // 插入模式串
        for (int i = 1; i <= n; ++i) {
            cin >> s;
            auto u = rot;
            for (auto c : s) {
                int idx = charToIndex(c);
                if (!u->ch[idx]) u->ch[idx] = new Node(); // 创建新节点
                u = u->ch[idx];
            }
            ++u->cnt; // 当前字符串结束，计数+1
        }

        // 对字典树进行后续处理，累加子节点的计数
        rot->dfs();

        // 查询每个字符串前缀的出现次数
        for (int i = 1; i <= q; ++i) {
            cin >> s;
            bool flag = true;
            auto u = rot;

            for (auto c : s) {
                int idx = charToIndex(c);
                if (u->ch[idx]) {
                    u = u->ch[idx];
                } else {
                    flag = false;
                    break;
                }
            }

            cout << ((flag) ? u->cnt : 0) << '\n';
        }
    }

    return 0;
}
