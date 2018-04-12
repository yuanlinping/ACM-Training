#include <bits/stdc++.h>
using namespace std;

int const maxn = 505;

int fa[maxn],del[maxn],vis[maxn],ans[maxn];   //del ʧ�س������У�vis ��ǳ����Ƿ���ɾ��״̬  ans��ӳ��к����ͨ����Ŀ 
int pa[maxn][maxn];
int cnt;

int Find(int i){
	return fa[i] == i? i: fa[i] = Find(fa[i]);
}

void Union(int i, int j){
	int fa1 = Find(i);
	int fa2 = Find(j);
	if(fa1 != fa2){
		cnt--;   //�ϲ�ʱ��ͨ����Ŀ���� 
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
	for(int i = 0;i < n; i++)    //�����ĳ���ɾ����ĳ�ʼ���鼯 
		if(vis[i] != 1)
			for(int j = 0; j < n; j++){
				if(vis[j] != 1 && pa[i][j]) Union(i,j);
			}
	
	ans[k] = cnt;
	for(int i = k - 1; i >= 0; i--){  //ÿ���һ�����и��²��鼯 
		int ii = del[i];
		cnt++;
		vis[ii] = 0;
		for(int j = 0; j < n; j++) 
			if(vis[j] != 1 && pa[ii][j]) Union(ii,j);
		ans[i] = cnt;    //��Ӻ���ͨ����Ŀ 
	}
	
	for(int i = 0; i < k ; i++) printf("%d ",ans[i]);
	printf("\n");
	
	for(int i = 0; i < k; i++){
		if(ans[i] < ans[i + 1]) printf("Red Alert: City %d is lost!\n",del[i]);
		else printf("City %d is lost.\n",del[i]);
	}
	if(k == n) printf("Game Over.");
	
}
