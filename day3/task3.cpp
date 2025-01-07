# include<iostream>
# include<vector>
# include<math.h>

using namespace std;

int m;

int main ()
{
    cin >> m;
    for (int i = sqrt(2 * m); i > 1; -- i )
    {
        if ((((2 * m) % i) == 0) && ((i + (2 * m % 2)) % 2) )   // i 和 j为一奇一偶才行
        {
            int j = 2 * m / i;
            cout << (j - i + 1) / 2 << " " << (i + j - 1) / 2 << endl;
        }
    }
    return 0;
}