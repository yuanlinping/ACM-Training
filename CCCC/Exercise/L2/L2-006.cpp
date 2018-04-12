#include<cstdio>
#include<queue>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

const int maxn=35;

int lef[maxn],rig[maxn],in[maxn],post[maxn];
int n;

int Tree(int L1,int R1,int L2,int R2){
	if(L1>R1)return -1;
	int root=post[R1];    // 注意根都是在后序遍历或者先序中取的 
	int lenl,lenr;
	for(int i=L2;i<=R2;i++) if(in[i]==root){lenl=i-L2; break;}   //i从L2开始，即中序的头 
	lenr=R2-L2-lenl;
	lef[R1]=Tree(L1,L1+lenl-1,L2,L2+lenl-1);
	rig[R1]=Tree(R1-lenr,R1-1,R2-lenr+1,R2);
	return R1;   //返回的也是在后序遍历或者先序中索引 
}
int main(){
//	freopen("data006.txt","r",stdin); 
	scanf("%d",&n);
	rep(i,n) scanf("%d",&post[i]);
	rep(i,n) scanf("%d",&in[i]);
	Tree(0,n-1,0,n-1);    
	
	queue<int>q;
	q.push(post[n-1]);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		int k;
		rep(i,n)if(post[i]==t){k=i;break;}		 //保存的是值，而不是下标索引  那么如果用重复 的值怎么办 
		if(lef[k]!=-1) q.push(post[lef[k]]);
		if(rig[k]!=-1) q.push(post[rig[k]]);
		if(t==post[n-1]) printf("%d",t);
		else printf(" %d",t);
	}
}
