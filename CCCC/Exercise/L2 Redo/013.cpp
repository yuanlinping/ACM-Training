#include <bits/stdc++.h>
using namespace std;

int const maxn = 505;

int fa[maxn],del[maxn],vis[maxn],ans[maxn];   //del 失守城市序列，vis 标记城市是否处于删除状态  ans添加城市后的连通块数目 
int pa[maxn][maxn];
int cnt;

int Find(int i){
	return fa[i] == i? i: fa[i] = Find(fa[i]);
}

void Union(int i, int j){
	int fa1 = Find(i);
	int fa2 = Find(j);
	if(fa1 != fa2){
		cnt--;   //合并时连通块数目减少 
//		fa1 > fa2 ? fa[fa1] = fa2 : fa[fa2] = fa1;
		fa[fa1] = fa2; 
	}
}

int main(){
//	freopen("data013.txt","r",stdin);
	int n,m,k;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++) fa[i] = i;
	for(int i = 0; i < m; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		pa[x][y] = pa[y][x] = 1;
	}
	
	scanf("%d",&k);
	for(int i = 0; i < k; i++){scanf("%d",&del[i]); vis[del[i]] = 1;}
	
	cnt = n - k;
	for(int i = 0;i < n; i++)    //给出的城市删除后的初始并查集 
		if(vis[i] != 1)
			for(int j = 0; j < n; j++){
				if(vis[j] != 1 && pa[i][j]) Union(i,j);
			}
	
	ans[k] = cnt;
	for(int i = k - 1; i >= 0; i--){  //每添加一个城市更新并查集 
		int ii = del[i];
		cnt++;
		vis[ii] = 0;
		for(int j = 0; j < n; j++) 
			if(vis[j] != 1 && pa[ii][j]) Union(ii,j);
		ans[i] = cnt;    //添加后连通块数目 
	}
	
	for(int i = 0; i < k ; i++) printf("%d ",ans[i]);
	printf("\n");
	
	for(int i = 0; i < k; i++){
		if(ans[i] < ans[i + 1]) printf("Red Alert: City %d is lost!\n",del[i]);
		else printf("City %d is lost.\n",del[i]);
	}
	if(k == n) printf("Game Over.");
	
}
