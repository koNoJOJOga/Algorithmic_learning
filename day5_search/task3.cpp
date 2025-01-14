# include <iostream>

using namespace std;

int n;
bool a[102];

int main ()
{
    cin >> n;

    cout << n << endl;
    for (int i = 1; i <= n; ++ i )
    {
        for (int j = 1; j <= n; ++ j)
        {
            if (j != i)
            {
                if (a[j]) a[j] = 0;
                else a[j] = 1;
            }
            cout << a[j];
        }
        cout << endl;
    }
}