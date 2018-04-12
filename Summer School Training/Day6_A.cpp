#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1005;
int f[maxn];            //以第i个数结尾的上升序列包含最多的数 
int num[maxn];   //存放数列（从i=1开始） 
int main(){
	int N;
	scanf("%d",&N);
	for (int k=1;k<=N;k++){
		scanf("%d",&num[k]);
	}
	
	f[1]=1;
    int res=1;
    for(int i=2;i<=N;i++){
        f[i]=1;
    	for(int j=1;j<i;j++){	
	     	if(num[j]<num[i]){
    	      f[i]=max(f[j]+1,f[i]);
			}
		}
		res=max(res,f[i]);
	}
	printf("%d",res);
	return 0;
} 
