#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1005;
int f[maxn];            //�Ե�i������β���������а��������� 
int num[maxn];   //������У���i=1��ʼ�� 
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
