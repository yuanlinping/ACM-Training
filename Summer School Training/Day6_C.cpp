#include <iostream>
#include <cstdio> 
#include<cstring> 
using namespace std;

const int num=21;
const int maxn=15005;

int r[num];   //����֧��ľ��� 
int w[num];  //��������� 
int dp[num][maxn];//�ﵽ����i������֮��ƽ���Ϊj��ԭʼ+7500����״̬�ķ�����

int main(){
	int C,G;
	scanf("%d%d",&C,&G);
	for(int i=1;i<=C;i++){
		scanf("%d",&r[i]);
	}
	
	for(int i=1;i<=G;i++){
		scanf("%d",&w[i]);
	}
	
    memset(dp,0,sizeof(dp));
    dp[0][7500]=1;   //һ�������ҿɴﵽƽ��״̬
	for(int i=1;i<=G;i++){
		for(int j=0;j<=15000;j++){
			if(dp[i-1][j]){
				for(int k=1;k<=C;k++){
					dp[i][j+w[i]*r[k]]+=dp[i-1][j];
				}
			}
		}
	} 
	printf("%d",dp[G][7500]);
} 
