# include <iostream>
# include <vector>
using namespace std;

int n;
vector<int> father(1001, 0);

void init () {
    for (int i = 0; i <= n; ++ i )
        father[i] = i;
    return;
}

int find (int u) {
    return father[u] == u ? u : father[u] = find(father[u]);
}

bool isSame (int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

void merge (int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return ;
    father[v] = u;
    return ;
}

int main () {
    int s, t;
    cin >> n;
    init();
    while (n -- ) {
        cin >> s >> t;
        if (isSame(s, t)) {
            cout << s << " " << t << endl;
            return 0;
        }
        else 
            merge(s, t);
    }
    return 0;
}