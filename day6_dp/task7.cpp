#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> dp(n+1, 0);
    
    for (int i = 0; i < m; ++ i ) {
        int v, p;
        cin >> v >> p;
        for (int cost = n; cost >= v; -- cost ) dp[cost] = max(dp[cost], dp[cost - v] + v * p);
    }
    
    cout << dp[n] << endl;
    return 0;
}
