#include <cstdio>
#include <cctype>
char tmp[1000010];
int cnt = 0, Max = 0;
char getch()
{
    ++cnt;
    if(cnt > Max)
    {
        cnt = 1;
        Max = fread(tmp+1, 1, 1000000, stdin);
    }
    return tmp[cnt];
}
int getint()
{
    int res = 0;
    char ch = getch();
    while(!isdigit(ch))
        ch = getch();
    while(isdigit(ch))
        res = res * 10 + (ch - '0'), ch = getch();
    return res;
}

int n, p;
int a[5000010], b[5000010];
int main()
{
    n = getint(), p = getint();
    for(int i = 1; i <= n; i++)
        a[i] = getint();
    for(int i = 1; i <= p; i++)
    {
        int x = getint(), y = getint(), z = getint();
        b[x] += z;
        b[y+1] -= z;
    }
    
    int sum = 0, ans = 1000000000;
    for(int i = 1; i <= n; i++)
    {
        sum += b[i];
        if(a[i] + sum < ans)
            ans = a[i] + sum;
    }
    printf("%d\n", ans);
    return 0;
}