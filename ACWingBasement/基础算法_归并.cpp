#include <iostream>

using namespace std;

const int N = 1000010;

int n;
int q[N], tmp[N];   // 相比于快排会多需要一个tmp数组

void merge_sort(int q[], int l, int r) {
    if (l >= r) return; // 一个或为空return;

    int mid = l + r >> 1;   // k表示tmp里多少个数，i、j分别指向左右半边的起点

    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);   // 分治，将其分成大小为1的小块

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j]) tmp[k ++] = q[i ++];
        else tmp[k ++] = q[j ++];
    }
    while (i <= mid) tmp[k ++] = q[ i ++];
    while (j <= r) tmp[k ++] = q[j ++];
    
    for (i = 0, j = 0; i <= r; i ++, j ++) q[i] = tmp[j];   // 把tmp复制到q里面去并输出
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);

    merge_sort(q, 0, n-1);

    for (int i = 0; i < n; i ++) printf("%d", q[i]);

    return 0;
}