#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int num=3405;
const int pa=12885;

int dp[pa]; 
int wei[num];
int val[num];
int N,M;

int main(){
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++){
		scanf("%d%d",&wei[i],&val[i]);
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=N;i++){
		for(int j=M;j>=wei[i];j--){
		     dp[j]=max(dp[j],dp[j-wei[i]]+val[i]);
		}
	}
	
	printf("%d",dp[M]);
}
