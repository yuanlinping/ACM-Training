#include <bits/stdc++.h>
using namespace std;

const int maxn = 35;
int post[maxn],in[maxn];

struct Node{
	int val;
	Node *lef,*rig;
};

Node *root;

Node* build(int l1,int r1,int l2,int r2){
	if(l1 > r1) return NULL;
	Node *t = new Node();
	if(l1 == r1){
		t->val = post[r1];
		t->lef = NULL;
		t->rig = NULL;
		return t;
	}
	int k = post[r1],lenl,lenr;
	for(lenl = l2; lenl <= r2;lenl++) if(in[lenl] == k) break;
	lenl -= l2; lenr = r2 - l2 - lenl;
	t->val = k;
	t->lef = build(l1,l1 + lenl - 1,l2,l2 + lenl - 1);
	t->rig = build(r1 - lenr,r1 - 1,r2 - lenr + 1,r2);
	return t;
}

void BFS(){
	queue<Node*>que;
	que.push(root);
	while(!que.empty()){
		Node* cur = que.front();que.pop();
		if(cur == root) printf("%d",cur->val);
		else printf(" %d",cur->val);
		if(cur->lef!=NULL) que.push(cur->lef);
		if(cur->rig!=NULL) que.push(cur->rig);
	}
}
int main(){
//	freopen("data006.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++) scanf("%d",&post[i]);
	for(int i = 0;i < n;i++) scanf("%d",&in[i]);
	root = NULL;
	root = build(0,n-1,0,n-1);
	BFS();
	return 0;
}
