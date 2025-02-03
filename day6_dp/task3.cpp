# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++ i ) cin >> a[i];

    int current_max = a[0];
    int global_max = a[0];

    for (int i = 1; i < n; ++ i ) {
        current_max = max (a[i], current_max + a[i]);
        global_max = max (global_max, current_max);
    }

    cout << global_max << endl;

    return 0;
}