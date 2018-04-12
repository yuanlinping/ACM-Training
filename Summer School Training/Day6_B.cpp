#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int maxn=105;
char bracket[maxn];
int dp[maxn][maxn];
int ans[maxn];

int search(int l,char a[]){
	for(int i=l-1;i>0;i--){
		for (int j=i+1;j<=l;j++){
			dp[i][j]=dp[i+1][j];
			if(bracket[i]=='('||bracket[i]=='['){
				for(int k=i+1;k<=j;k++){
					if((bracket[i]=='('&&bracket[k]==')')||(bracket[i]=='['&&bracket[k]==']')){
						dp[i][j]=max(dp[i][j],dp[i+1][k-1]+dp[k][j]+2);
					}
				}
			}
		}
	}
	return dp[1][l];
}




int main(){
	int t=0;
	while(scanf("%s",bracket+1)){
			if(strcmp(bracket+1,"end")==0) break;
			memset(dp,0,sizeof(dp));
			int len=strlen(bracket+1);
			ans[t]=search(len,bracket+1);
			t++;
	}
	for(int z=0;z<t-1;z++){
		printf("%d\n",ans[z]);
	}
	printf("%d",ans[t-1]);
	
	return 0;
}
