#include<cstdio>
#include<algorithm>
#include<cstring>
#include<functional>
using namespace std;

const int maxn=1005;

int pre[maxn],in[maxn],lef[maxn],rig[maxn];
bool isBST=true;

int Tree(int L1,int R1,int L2,int R2){    //依据先序和中序建树    要是想验证什么的，构造例子的时候不要用完全二叉树 
	if(L1>R1) return -1;
	int root=pre[L1];
	int lenl,lenr,i;
	for(i=L2;i<=R2;i++)  if(root==in[i]) {lenl=i-L2;break;}
	if(i>R2) {
		isBST=false;
		return -1;
	}
	lenr=R2-L2-lenl;
	lef[L1]=Tree(L1+1,L1+lenl,L2,L2+lenl-1);
	rig[L1]=Tree(R1-lenr+1,R1,R2-lenr+1,R2);
	return L1;	
}

void postTra(int root){
	if(root==-1) return;
	postTra(lef[root]);
	postTra(rig[root]);
	if(root==0)printf("%d",pre[root]);	
	else printf("%d ",pre[root]);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
		in[i]=pre[i];
	}
	sort(in,in+n);    //判断其本身是不是BST 
	Tree(0,n-1,0,n-1);    
	if(isBST) {
		printf("YES\n");
		postTra(0); 
	}
	
	
	/*
	*下面中，由于Tree中的算法缺陷，当有重复的数的时候，会出错。就是样例那种情况过不了 
	*/
	else{     //判断其是不是 BST的镜像 
		isBST=true;
		sort(in,in+n,greater<int>());
		memset(lef,0,sizeof(lef));
		memset(rig,0,sizeof(rig));
		Tree(0,n-1,0,n-1);
		if(isBST){
		printf("YES\n");
		postTra(0);
		}
		else printf("NO");
	} 
} 
