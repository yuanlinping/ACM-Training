#include <cstdio>
using namespace std;

const int maxn=1005;
int main(){
	int n,num[maxn];
	int cntodd=0,cnteven=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		if(num[i]%2==0) cnteven++;
		else cntodd++;
	}
	printf("%d %d",cntodd,cnteven);
} 
