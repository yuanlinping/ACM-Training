#include <cstdio>
#include <stack>
using namespace std;
const int maxn = 505;
const int inf = 1000;
int n, m, S, D;
int dis[maxn], team[maxn], e[maxn][maxn], num[maxn], w[maxn], pre[maxn];
bool vis[maxn];

int main() {
    scanf("%d%d%d%d", &n, &m, &S, &D);
    for(int i = 0; i < n; i++)
        scanf("%d", &team[i]);
	for(int i = 0;i < n;i++) dis[i] = inf;
    int a, b, c;
    while(m) {
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = c;
        e[b][a] = c;
        m--;
    }
    
    dis[S] = 0;
    w[S] = team[S];
    num[S] = 1;
    for(int i = 0; i < n; i++) {     
		int x, minn = inf;
        for(int j = 0; j < n; j++)  // 找dis最小的点
			if(!vis[j] && dis[j] < minn)  minn = dis[x=j];
			
        vis[x] = true;
        for(int v = 0; v < n; v++) {
            if(!vis[v] && e[x][v] != 0) {
                if(dis[x] + e[x][v] < dis[v]) {
                    dis[v] = dis[x] + e[x][v];
                    num[v] = num[x];
                    w[v] = w[x] + team[v];
                    pre[v] = x;
                } else if(dis[x] + e[x][v] == dis[v]) {
                    num[v] = num[v] + num[x];
                    if(w[x] + team[v] > w[v]) {
                        w[v] = w[x] + team[v];
                        pre[v] = x;
                    }
                }
            }
        }
    }
    printf("%d %d\n", num[D], w[D]);
    
    stack<int>path;	//打印 
	path.push(D);
	int temp=D;
	while(pre[temp]!=S){
		temp=pre[temp];
		path.push(temp);
	}
	printf("%d",S);
	while(!path.empty()){printf(" %d",path.top());path.pop();} 
    return 0;
}
