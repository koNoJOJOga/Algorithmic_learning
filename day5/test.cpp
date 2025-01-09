#include<iostream>
using namespace std;
bool f;//f用来判断是否有符合条件的数
int main()
{
    int k,a1;
    cin>>k;
    for(int i=10000;i<=30000;i++)
    {
      if(i/100%k==0)//判断1到3位
          if((i/10-i/10000*1000)%k==0)//判断2到4位
            if((i-i/1000*1000)%k==0) cout<<i<<endl,f=1;//判断2到5位，若都符合，输出该数，f为真，继续搜索
    }
    if(!f) cout<<"No";
    return 0;
}