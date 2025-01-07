#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<long long> elements(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &elements[i]);
    }
    
    stable_sort(elements.begin() + 1, elements.end());
    
    vector<long long> suffixSum(n + 2);
    for (int i = n; i >= 1; i--) {
        suffixSum[i] = suffixSum[i + 1] + elements[i];
    }
    
    int operation, k, p;
    long long delta = 0;
    while (m--) {
        scanf("%d", &operation);
        if (operation == 1) {
            scanf("%d", &k);
            delta += k;
        } else {
            p = lower_bound(elements.begin() + 1, elements.end(), -delta) - elements.begin();
            if (p == n + 1) {
                printf("0\n");
            } else {
                printf("%lld\n", suffixSum[p] + (n - p + 1) * delta);
            }
        }
    }
    
    return 0;
}