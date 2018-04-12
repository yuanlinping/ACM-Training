#include <bits/stdc++.h>
using namespace std;

const int maxn=1005;
int num[maxn];

int main(){
//	freopen("002.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int x;
			scanf("%d",&x);
			num[x]++;
		}
	}
	
	int x=0,maxx=0;
	for(int i=1;i<=1000;i++){
		if(num[i]>=maxx){
			x=i;
			maxx=num[i];
		}
	}
	printf("%d %d",x,num[x]);
}
