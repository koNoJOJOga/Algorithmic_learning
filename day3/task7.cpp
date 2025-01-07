#include <cstdio>
#define gc getchar()
#define pc(c) putchar(c)
#define N 10007
int n;
int op;
int q[N],qh,qt;
int read(){
	int t=0;
	char c=gc;
	while(c<'0'||c>'9') c=gc;
	while(c>='0'&&c<='9') t=10*t+(c^48),c=gc;
	return t;
}
void write(int x){
	if(x<10){
		pc(x|48);
		return;
	}
	write(x/10);
	pc((x%10)|48);
}
int main(){
	//freopen("B3616.out","w",stdout);
	n=read();
	while(n--){
		op=read();
		switch(op){ 
			case 1:{
				q[++qh]=read();
				break; 
			}
			case 2:{
				if(qt+1>qh){
					puts("ERR_CANNOT_POP");
				}
				else{
					++qt;
				}
				break;
			}
			case 3:{
				if(qt+1>qh){
					puts("ERR_CANNOT_QUERY");
				}
				else{
					write(q[qt+1]);
					puts("");
				}
				break;
			}
			case 4:{
				write(qh-qt);
				puts("");
				break;
			}
		} 
	}
	return 0;
}