# include<iostream>

using namespace std;

int n, m, p, person[5002];

int find(int x)
{
    if (person[x] == x) return x;
    else
    {
        person[x] = find(person[x]);
        return person[x];
    }
}

void merge(int a, int b)
{
    person[find(a)] = find(b);
}

int main ()
{
    cin >> n >> m >> p;
    for (int i = 1; i < n + 1; ++ i ) person[i] = i; // 初始化

    for (int i = 0; i < m; ++ i )
    {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    for (int i = 0; i < p; ++ i )
    {
        int x, y;
        cin >> x >> y;
        if (find(x) == find(y)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}