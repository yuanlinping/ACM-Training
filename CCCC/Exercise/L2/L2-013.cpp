#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=505;
const int maxm=5005;

int ff[2][maxn],ct[maxn][maxn],del[maxn],fat[maxn];

int find(int i,int *f){
	return f[i]==i? i : f[i]=find(f[i],f);
}

void Union(int i,int j,int *f){
	int fa1 = find(i,f);
	int fa2 = find(j,f);
	if(fa1 == fa2) return;
	fa1>=fa2?f[i]=fa2:f[j]=fa1; //保留这个是因为 怕之后没有节点合并时经过他，从而导致计数出错 
	fa1>=fa2?f[fa1]=fa2:f[fa2]=fa1; 
}

//bool isConnected(int i,int j,int *f){
//	int fa1=find(i,f);
//	int fa2=find(j,f); 
//	return fa1==fa2;
//}

int count(int *f,int nn){
	memset(fat,0,sizeof(fat));
	int cnt=0;
	for(int i=0;i<nn;i++){
		if(f[i]!=-1){
			if(fat[f[i]]==0){
				fat[f[i]]=1;
				cnt++;
			}
		}
		
	}
	return cnt;
}

int main(){
//	freopen("data013.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		ct[v1][v2]=ct[v2][v1]=1;
	}
	
	for(int j=0;j<n;j++) ff[0][j]=j;  //最开始的并查集 
	for(int x=0;x<n;x++)
		for(int y=x+1;y<n;y++){
			if(ct[x][y]==1) Union(x,y,ff[0]);
		}
		
//	for(int j=0;j<n;j++) printf("%d ",ff[0][j]);
//	printf("\n");
			
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int lc;
		scanf("%d",&lc);
		del[lc]=1;
		for(int z=lc+1;z<n;z++)if(ct[lc][z]) ct[lc][z]=0;
		for(int z=0;z<lc;z++)if(ct[z][lc]) ct[z][lc]=0;
		
		int in=(i+1)%2;
		for(int j=0;j<n;j++) if(del[j]!=1)ff[in][j]=j;else ff[in][j]=-1;
		for(int x=0;x<n;x++)
			for(int y=x+1;y<n;y++){
				if(ct[x][y]==1) Union(x,y,ff[in]);
			}
			
//		for(int j=0;j<n;j++) printf("%d ",ff[in][j]);
//		printf("\n");
		
		bool isChanged=false;
//		for(int x=0;x<n;x++){   //我当时为什么写了一个二重循环？？？？ 
//			for(int y=x+1;y<n;y++){
//				if(x!=lc&&y!=lc)
//				{	int cnt1=count(ff[in],n);   		//好吧，这个也会= = 
//					int cnt2=count(ff[(in+1)%2],n);
////					bool flag1=isConnected(x,y,ff[in]);   //用这一函数 会超时 
////					bool flag2=isConnected(x,y,ff[(in+1)%2]);
//					if(cnt1>cnt2){
//						isChanged=true;
//						break;
//					}	
//				}
//				
//			}
//			if(isChanged) break;
//		}
//		
		int cnt1=count(ff[in],n);
		int cnt2=count(ff[(in+1)%2],n);
		if(cnt1>cnt2)
			isChanged=true;
				
		if(isChanged) printf("Red Alert: City %d is lost!\n",lc);
		else printf("City %d is lost.\n",lc);
	}
	
	if(k==n) printf("Game Over.");
	return 0;
}

