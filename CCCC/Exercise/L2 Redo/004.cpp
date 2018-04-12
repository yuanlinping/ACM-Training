#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int pre[maxn];
bool isB;
int n;

struct node{
	int val;
	node *lef,*rig;
};

node* build(int l, int r,char c){
	if(l > r) return NULL;
	node *rt = new node();
	if(l == r){
		rt->val = pre[l];
		rt->lef = NULL;
		rt->rig = NULL;
		return rt;
	}
	
	rt->val = pre[l];
	int p = l + 1;
	if(c == '>'){    //�����Ƕ��������� 
		for(;p <= r; p++) if(pre[p] >= pre[l]) break;
		for(int j = p; j < n; j++) if(pre[j] < pre[l]){ isB = false; return NULL;}
	}
		
	else if(c == '<'){   //�侵���Ƕ��������� 
		for(;p <= r; p++) if(pre[p] < pre[l]) break;
		for(int j = p; j < n; j++) if(pre[j] >= pre[l]){ isB = false; return NULL;}
	}

	rt->lef = build(l + 1,p - 1,c);
	rt->rig = build(p,r,c);
	return rt;
}

void print(node* rt,int i){
	if(rt == NULL) return;
	print(rt->lef, i + 1);
	print(rt->rig, i + 1);
	if(i == 0) printf("%d",rt->val);  //����ӡ��� 
	else printf("%d ",rt->val);
}


int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d",&pre[i]);
	isB = true;
	node *root = build(0,n - 1, '>');
	
	if(isB) {printf("YES\n");print(root,0);}   //�б��� 
	else{   //�о��� 
		isB = true;
		root = build(0,n - 1, '<');
		if(isB){printf("YES\n");print(root,0);} 
		else printf("NO");   //���������д���� = = ����wa 
	}

} 
