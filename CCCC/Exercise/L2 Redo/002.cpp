#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
const int maxv = 10005;

int llist[2][maxn],res[maxn],del[maxn];
int  ab[maxv];

int main(){
//	freopen("002.txt","r",stdin); 
	int st,n;
	scanf("%d%d",&st,&n);
	for(int i = 0;i < n;i++){
		int add;
		scanf("%d",&add);
		scanf("%d%d",&llist[0][add],&llist[1][add]);   //list[0]存值，list[1]存下一个节点 
	}
	
	/*
	*通过自身地址和next遍历链表，对每一个进行节点的值进行判断 
	*/
	int inr = 0, ind = 0;    
	int next = st;
	while(next != -1){
		int val = abs(llist[0][next]);
		if(ab[val]) del[ind++] = next;
		else {ab[val] = 1; res[inr++] = next; }
		next = llist[1][next];
	}
	
	del[ind] = -1;
	res[inr] = -1;
	

	for(int i = 0;i < inr-1; i++) printf("%05d %d %05d\n",res[i],llist[0][res[i]],res[i+1]);
	printf("%05d %d %d\n",res[inr-1],llist[0][res[inr-1]],res[inr]);
	if(ind>0){   //当有删除节点时才输出 
		for(int i = 0;i < ind-1; i++) printf("%05d %d %05d\n",del[i],llist[0][del[i]],del[i+1]);
	    printf("%05d %d %d\n",del[ind-1],llist[0][del[ind-1]],del[ind]);
	}

} 
