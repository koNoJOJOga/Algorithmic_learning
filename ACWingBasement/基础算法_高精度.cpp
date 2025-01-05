#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6 + 10; // +10 防止出现边界问题

// C = A + B
vector<int> add(vector<int> &A, vector<int> &B) // 小细节，如果不加引用会把整个数组copy一遍
{
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i ++ ) 
    {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(1);
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b;  // a = "123456"
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');    // A = [6, 5, 4, 3, 2, 1]
    for (int j = b.size() - 1; j >= 0; j -- ) B.push_back(b[j] - '0');    

    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);
    return 0;
}