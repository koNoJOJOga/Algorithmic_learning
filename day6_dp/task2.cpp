# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

int main () {

    int n;
    cin >> n;
    vector<int> a(n), f(n, 1);  

    for (int i = 0; i < n; ++ i ) cin >> a[i];  

    int result = 1; // 用于记录最长长度

    for (int i = 1; i < n; ++ i ) {
        for (int j = 0; j < i; ++ j )
            if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
        result = max(result, f[i]);
    }

    cout << result << endl;

    return 0;
}