#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn=10005;
const int kind=505;
const int INF=0x3f3f3f3f;

int dp[maxn];
int P[kind],W[kind];     // p是价值  w是重量 
int T;
int res[maxn];          //用于记录每种情况对应下的最大值，以便输出 


int main(){
	scanf("%d",&T);  //几种情况 
	for(int i=1;i<=T;i++){
		int N,E,F;
		scanf("%d%d%d",&E,&F,&N);  //E是纯猪重量，F是放了钱之后的猪重量  N是几种硬币 
		int net=F-E;	//钱重量
		memset(P,0,sizeof(P));             // 在有多种情况下共用一个数组记录数组，每次都要清零的！！！！！！ 
		memset(W,0,sizeof(W));
		for(int j=1;j<=N;j++){
			scanf("%d%d",&P[j],&W[j]);
		}
		
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int k=1;k<=N;k++){
		for(int v=W[k];v<=net;v++){
			dp[v]=((dp[v])>=(dp[v-W[k]]+P[k]))?(dp[v-W[k]]+P[k]):dp[v];
		}
	}
	res[i]=dp[net];
   	}
   	
   	for(int z=1;z<T;z++){
   		if(res[z]==INF)printf("This is impossible.\n");
    	else printf("The minimum amount of money in the piggy-bank is %d.\n",res[z]);
   		 }
    if(res[T])printf("This is impossible.");
    else printf("The minimum amount of money in the piggy-bank is %d.",res[T]);
    
	return 0;
}
