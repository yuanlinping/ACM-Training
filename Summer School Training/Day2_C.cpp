#include<stdio.h>
const int maxn=100001;
int A[maxn];              //¼ÇÂ¼ÀûÈó 
int D[maxn]; 
int main(){
	int N;
	long long most=0;
	bool x=0;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&A[i]);
	D[1]=A[1];	
	for(int j=2;j<=N;j++){
		D[j]=(A[j]>A[j]+D[j-1])?A[j]:A[j]+D[j-1];
	}
	most=D[1];
		for(int i=1;i<=N;i++)
		    if(D[i]>most) most=D[i];
		printf("%lld",most);
	return 0;
}
