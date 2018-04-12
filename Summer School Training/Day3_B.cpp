#include <iostream>
using namespace std;
const int maxn=21;
int idx[maxn][maxn];
int A,B,C;

void dfs(int m,int n){
	int h=C-m-n;                     //B当前的量 
	if(idx[m][n]==1)return;          //标记已到达的状态 
	if(m>A||h>B||n>C) return;        //当容器里的量超过体积时return 
	idx[m][n]=1;
	//printf("idx[%d][%d]=%d h=%d\n",m,n,idx[m][n],h);
	if(m>C-n)dfs(m-C+n,C);            //A->C
	else dfs(0,m+n);
	
	if(n>A-m)dfs(A,n-A+m);           //C->A 
	else dfs(m+n,0);
	
	if(m>B-h)dfs(m-B+h,n);          //A->B
	else dfs(0,n);
	
	if(n>B-h)dfs(m,n-B+h);         //C->B 
	else dfs(m,0);
	
	if(h>A-m)dfs(A,n);           //B->A 
	else dfs(m+h,n);
	
	if(h>C-n)dfs(m,C);            //B->C
	else dfs(m,h+n);
}

int main(){
	    scanf("%d%d%d",&A,&B,&C);
	    dfs(0,C);
	    bool f=false;
	    for(int k=0;k<=C;k++){
	  	if(idx[0][k]==1) {
	  		if(!f){
	  			printf("%d",k);
	  			f=true;
			  }
	        else printf(" %d",k);	
	}
}
 
	
	return 0;
}
