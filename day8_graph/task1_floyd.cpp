# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

const int INF = 1e6;

int main () {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<vector <int>> g(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; ++ i ) {
        g[i][i] = 0;
        int l, r;
        cin >> a[i] >> l >> r;

        if (l > 0) g[i][l] = g[l][i] = 1;
        if (r > 0) g[i][r] = g[r][i] = 1;
    }

    // floyd
    for (int k = 1; k <= n; ++ k )  // take k as the intermediate node 
        for (int i = 1; i <= n; ++ i )  // enumerate the starting point i 
            // if i == k need not upgrade
            if (i != k) 
                for (int j = 1; j <= n; ++ j )  // enumerate the ending point j
                    if (i != j && k != j) 
                        g[i][j] = min (g[i][j], g[i][k] + g[k][j]);

    int bestTotal = INF * INF;
    for (int i = 1; i <= n; ++ i ) {
        int total = 0;
        for (int j = 1; j <= n; ++ j )
            total += g[i][j] * a[j];
        bestTotal = min (bestTotal, total);
    }

    cout << bestTotal << endl;

    return 0;
}