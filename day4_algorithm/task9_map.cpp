# include <iostream>
# include <map>

using namespace std;

typedef long long ll;

int n;
ll d[200002];
ll c, sum;
map<ll, ll> m;

int main ()
{
    cin >> n >> c;
    for (int i = 0; i < n; ++ i )
    {
        int temp;
        cin >> temp;
        d[i] = temp;
        ++ m[d[i]];
    }
    
    for (int i = 0; i < n; ++ i ) sum += m[d[i] - c];
    
    cout << sum;
    return 0;
}