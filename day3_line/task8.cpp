#include<iostream>
using namespace std;
const int N = 1e6+10;

int r[N];

void do1(){
	int x,y;
	cin>>x>>y;
	r[y] = r[x];
	r[x] = y;
}

void do2(){
	int x;
	cin>>x;
	cout<<r[x]<<"\n";//输出x右边的数 
}

void do3(){
	int x;
	cin>>x;
	r[x] = r[r[x]];
}

int main(){
	int q;
	cin>>q;
	while(q--)
	{
		int d;//操作编号
		cin>>d;
		switch(d){
			case 1 :do1();break;
			case 2 :do2();break;
			case 3 :do3();break;
		}
	}
	
	return 0;
}
