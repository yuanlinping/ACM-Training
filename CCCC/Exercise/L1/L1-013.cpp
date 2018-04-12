#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=15;
int faci[maxn];
int fac(int n){   //带记忆搜索的阶乘函数 
	if(n==1) {
		faci[1]=1;
		return faci[1];
	}
//	if(faci[n]) return faci[n];
//	else return n*fac(n-1);
	faci[n]=faci[n]? faci[n]:n*fac(n-1);
	return faci[n];
}

int main(){
	int n,sum=0;
	scanf("%d",&n);
	memset(faci,0,sizeof(faci));
	fac(n);
//	printf("%d\n",fac(n));
	for(int i=1;i<=n;i++) sum+=faci[i];
//	for(int i=1;i<=n;i++) printf("%d ",faci[i]);
	printf("%d",sum);
}
