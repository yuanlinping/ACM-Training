#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int INF = 100000000;
int tr[maxn],d[maxn],g[maxn];

int main(){
//	freopen("data014.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d",&tr[i]);
	for(int i = 0; i < n; i++) g[i] = INF;  //֮ǰ������д�ģ��������Ե���ˡ����б������Ǵ�С�����ŵ�ʱ�� g[n] = 0, loewr_bound()�õ��Ľ������ 
//	for(int i = 0; i < n + 5; i++) g[i] = INF;
	for(int i = 0; i < n; i++){
		int k = lower_bound(g+1,g+n+1,tr[i]) - g;
		d[i] = k;
		g[k] = tr[i];
	}
	int len;
	for(len = 1;len <= n; len++){
		printf("%d ",g[len]);
		if(g[len] == INF) break;
	}
	printf("%d",len - 1);
} 
