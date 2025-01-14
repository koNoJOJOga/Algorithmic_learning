# include <iostream>
# include <vector>
# include <string>

using namespace std;

class SegmentTree {
    private:
        vector<long long> tree;
        int n;

        void changePoint (int k, int l, int r, int x, int v) {
            if (x < l || x > r) return ;    // 不在范围
            if (l == r) {
                tree[k] += v;
                return ;
            }
            int mid = (l + r) / 2;
            changePoint(2 * k, l, mid, x, v);
            changePoint(2 * k + 1, mid + 1, r, x, v);
            tree[k] = tree[2 * k] + tree[2 * k + 1];
        }

        long long query (int k, int l, int r, int x, int y) {
            if (y < l || x > r) return 0;   // 区间无交集
            if (x <= l && r <= y) return tree[k];
            int mid = (l + r) / 2;
            return query(2 * k, l, mid, x, y) + query(2 * k + 1, mid + 1, r, x, y);
        }

        public:
            SegmentTree(int size) : n(size) {
                tree.resize(4 * size, 0);
            }

            void update(int x, int v) {
                changePoint(1, 1, n, x, v);
            }

            long long rangeQuery (int x, int y) {
                return query(1, 1, n, x, y);
            }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    SegmentTree segTree(n);

    for (int i = 0; i < m; ++ i ) {
        char op;
        int x, y;
        cin >> op >> x >> y;
        if (op == 'x') segTree.update(x, y);
        else if (op == 'y') cout << segTree.rangeQuery(x, y) << endl;
    }

    return 0;
}