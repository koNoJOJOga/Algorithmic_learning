#include<cstdio>
#include<cstring>
using namespace std; 

struct Monotone_queue
{
    static const int maxn=1000001;
    int n, k, a[maxn];
    int q[maxn], head, tail, p[maxn];
    
    void read()
    {
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; ++ i )
            scanf("%d", &a[i]);
    }
    
    void monotone_max()
    {
        head = 1;
        tail = 0;
        for(int i = 1; i <= n; ++ i )
        {
            while( head <= tail && q[tail] <= a[i])
                tail--;
            q[++tail]=a[i];
            p[tail]=i;
            while(p[head]<=i-k)
                head++;
            if(i>=k)printf("%d ",q[head]);
        }
        printf("\n");
    }
    
    void monotone_min()
    {
        head=1;
        tail=0;
        for(int i=1;i<=n;++i)
        {
            while(head<=tail&&q[tail]>=a[i])
                tail--;
            q[++tail]=a[i];
            p[tail]=i;
            while(p[head]<=i-k)
                head++;
            if(i>=k)printf("%d ",q[head]);
        }
        printf("\n");
        
    }
}worker;

int main()
{
    worker.read();
    worker.monotone_min();
    worker.monotone_max();
    return 0;
}