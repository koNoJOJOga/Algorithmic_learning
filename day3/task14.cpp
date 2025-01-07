#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[1000005];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        int i = 1;
        while (i <= n)
        {
            if (a[i] == i) // 相同 
                i++;
            else // 不同 
            {
                int maxv = a[i];
                int j = i + 1;
                maxv = max(maxv, a[j]);
                while (maxv > j)
                {
                    j++;
                    maxv = max(maxv, a[j]);
                }
                ans += j - i + 1;
                i = j + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}