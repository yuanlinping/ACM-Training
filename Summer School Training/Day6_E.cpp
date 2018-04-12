#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn=10005;
const int kind=505;
const int INF=0x3f3f3f3f;

int dp[maxn];
int P[kind],W[kind];     // p�Ǽ�ֵ  w������ 
int T;
int res[maxn];          //���ڼ�¼ÿ�������Ӧ�µ����ֵ���Ա���� 


int main(){
	scanf("%d",&T);  //������� 
	for(int i=1;i<=T;i++){
		int N,E,F;
		scanf("%d%d%d",&E,&F,&N);  //E�Ǵ���������F�Ƿ���Ǯ֮���������  N�Ǽ���Ӳ�� 
		int net=F-E;	//Ǯ����
		memset(P,0,sizeof(P));             // ���ж�������¹���һ�������¼���飬ÿ�ζ�Ҫ����ģ����������� 
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
