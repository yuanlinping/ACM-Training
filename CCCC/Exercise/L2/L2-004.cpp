#include<cstdio>
#include<algorithm>
#include<cstring>
#include<functional>
using namespace std;

const int maxn=1005;

int pre[maxn],in[maxn],lef[maxn],rig[maxn];
bool isBST=true;

int Tree(int L1,int R1,int L2,int R2){    //���������������    Ҫ������֤ʲô�ģ��������ӵ�ʱ��Ҫ����ȫ������ 
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
	sort(in,in+n);    //�ж��䱾���ǲ���BST 
	Tree(0,n-1,0,n-1);    
	if(isBST) {
		printf("YES\n");
		postTra(0); 
	}
	
	
	/*
	*�����У�����Tree�е��㷨ȱ�ݣ������ظ�������ʱ�򣬻������������������������� 
	*/
	else{     //�ж����ǲ��� BST�ľ��� 
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
