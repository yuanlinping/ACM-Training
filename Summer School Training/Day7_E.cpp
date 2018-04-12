#include<cstdio>
#include<cstring>

const int maxn=21;

char par[2*maxn];
int right[maxn];
int rgl[maxn];
int res[maxn];

int main(){
	int t;
	scanf("%d",&t);               //情况数
	 
	for(int i=1;i<=t;i++){
		int n;
		scanf("%d",&n);
		
		memset(par,'(',sizeof(par));       //括号全初始为（ 
		memset(right,0,sizeof(right));     //用于记录每个）前的（ 个数 
		memset(rgl,0,sizeof(rgl));         //用于记录）本身的位置 
	    memset(res,0,sizeof(res));         //转换为w序列后的结果 
	    
		for(int j=1;j<=n;j++){           //输入 每个）前的（ 个数
			scanf("%d",&right[j]);
		}
		
		int lp=0,rp=0;
		for(int j=1;j<=n;j++){
		    rgl[j]=right[j]+j;
			par[rgl[j]]=')';
			for(int k=rgl[j];k>=1;k--){
				if(par[k]==')') rp++;
				else if(par[k]=='(')lp++;
			    if(rp==lp) {res[j]=rp;break;} 
			}
			lp=0,rp=0;
		}
        bool f=true;
		for(int k=1;k<=n;k++){
			if(f){
				printf("%d",res[k]);
				f=false;
			}
			else printf(" %d",res[k]);
		}
		printf("\n");
	}
	return 0;
}
