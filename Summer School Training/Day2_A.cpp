#include <iostream>
#include <cstdio>
using namespace std; 
const int maxn=10000;
int C[maxn],A[maxn],P[maxn];
int main(){
	int N,S;
	scanf("%d%d",&N,&S);
	for(int i=1;i<=N;i++)
	   scanf("%d%d",&C[i],&A[i]);
	   
	P[1]=C[1];
	for(int i=2;i<=N;i++)
	   P[i]=(P[i-1]+S<C[i])?(P[i-1]+S):C[i];
	
	long long sum=0;
	for(int i=1;i<=N;i++){
		sum+=P[i]*A[i];
	}
	
	printf("%lld",sum);
	return 0;
}
