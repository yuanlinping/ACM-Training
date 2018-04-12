#include <bits/stdc++.h>
using namespace std;

const int maxn = 35;
int in[maxn], pre[maxn];

struct node{
	int val;
	node *lef, *rig;
};

node* BT(int l1,int r1,int l2,int r2){ //½¨Ê÷ 
	if(l1 > r1)return NULL;
	node *rt = new node();
	if(l1 == r1){
		rt->val = pre[l1];
		rt->lef = NULL;
		rt->rig = NULL;
		return rt; 
	}
	
	rt->val = pre[l1];
	int lenl = l2, lenr;
	for(;lenl <= r2; lenl++)
		if(in[lenl] == pre[l1]) break;
	lenl = lenl - l2;
	lenr = r2 - l2 -lenl;
	rt->lef = BT(l1 + 1, l1 + lenl, l2, l2 + lenl - 1);
	rt->rig = BT(r1 - lenr + 1, r1, r2 - lenr + 1,r2); 
	return rt;
}

void sswap(node* rt){   //¾µÃæ 
	if(rt == NULL) return;
	if(rt->lef == NULL && rt->rig == NULL) return;
	sswap(rt->lef);
	sswap(rt->rig);
	node *temp = rt->lef;
	rt->lef = rt->rig;
	rt->rig = temp;
}

int main(){
//	freopen("011.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d",&in[i]);
	for(int i = 0; i < n; i++) scanf("%d",&pre[i]);
	node* root = new node();
	root = BT(0,n - 1,0,n - 1);
	sswap(root);
	
	
	queue<node*>que;  //²ãÐò±éÀú 
	que.push(root);
	while(!que.empty()){
		node* temp = que.front();
		que.pop();
		if(temp->val == root->val) printf("%d",temp->val);
		else printf(" %d",temp->val);
		if(temp->lef != NULL) que.push(temp->lef);
		if(temp->rig != NULL) que.push(temp->rig);
	}
}

