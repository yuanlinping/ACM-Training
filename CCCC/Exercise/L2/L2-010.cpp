#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=105;

int fe[maxn][maxn];
 
int main(){
//	freopen("data010.txt","r",stdin);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		int x,y,re;
		scanf("%d%d%d",&x,&y,&re);
		fe[x][y]=fe[y][x]=re;
	} 
	for(int i=0;i<k;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(fe[x][y]==1) printf("No problem\n");
		else if(fe[x][y]==0)printf("OK\n");
		else{
			bool flag=true;
			for(int j=1;j<=n;j++)
				if(fe[x][j]==1&&fe[y][j]==1){   //这样子写仅仅只是直接的朋友是朋友，但是，题中讲了，间接的朋友也是朋友  这应该就是错误所在了 
					printf("OK but...\n");
					flag=false;
					break;
				}
			
			if(flag) printf("No way\n");
		}
	}
} 
