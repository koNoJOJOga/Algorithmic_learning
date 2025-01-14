# include <iostream>

using namespace std;

int sum;

int main ()
{
    int x, y, a, b, t;
    cin >> x >> y >> a >> b >> t;

    for (int i = 0; i < t; ++ i )
    {
        char c;
        cin >> c;
        if (c == 'E' && (a > x)) ++ x, ++ sum;
        if (c == 'N' && (b > y)) ++ y, ++ sum;
        if (c == 'W' && (a < x)) -- x, ++ sum;
        if (c == 'S' && (b < y)) -- y, ++ sum;

        if (x == a && y == b)
        {
            cout << sum;
            return 0;
        }
    }
    cout << "-1";

    return 0;
}