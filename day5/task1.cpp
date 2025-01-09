# include<iostream>

using namespace std;

bool flag;

int main ()
{
    int n;
    cin >> n;

    for (int i = 10000; i <= 30000; ++ i)
    {
        if (i / 100 % n == 0)
        {
            if ((i / 10 - i / 10000 * 1000) % n == 0)
            {
                if ((i - i / 1000 * 1000) % n == 0)
                {
                    cout << i << endl;
                    flag = 1;
                }
            }
        }
    }

    if (!flag) cout << "No";

    return 0;
}