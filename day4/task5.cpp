# include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

char a[10002], b[10002];

int main ()
{
    scanf("%s \n %s", &a, &b);
    int len = strlen(a), ans = 1;
    for (int i = 0; i < len - 1; ++ i )
    {
        for (int j = 0; j < len; ++ j)
        {
            if (a[i] == b[j] && a[i + 1] == b[j - 1]) ans *= 2;
        }
    }
    cout << ans;
    return 0;
}