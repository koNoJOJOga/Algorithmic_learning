# include<iostream>
# include<vector>

using namespace std;

int n, m;
vector<int> sum(100002);

int main ()
{
    cin >> n;
    for (int i = 1; i <=n; ++ i )
    {
        int temp;
        cin >> temp;
        sum[i] = sum[i - 1] + temp;
    }
    cin >> m;

    for (int i = 0; i < m; ++ i)
    {
        int l, r;
        cin >> l >> r;
        int result = sum[r] - sum[l - 1];
        cout << result << endl;
    }
}