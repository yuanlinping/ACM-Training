#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

struct ps{
	int f,m;
	char s[2];
}p[maxn]; 

set<int> fam[maxn];
set<int> jiao;
int vis[maxn];
queue<int>que[5];

void getFam(int lv){
	for(int i = 0;  i < 5; i++) 
		while(!que[i].empty()) que[i].pop();
	que[0].push(lv);
	for(int i = 0;i < 5; i++){
		while(!que[i].empty()){
			int cur = que[i].front();
//			printf("%d %d \n",i,cur);
			que[i].pop();
			fam[lv].insert(cur);
			if(i != 4){
//				printf("%d %d\n",p[cur].f,p[cur].m);
				if(p[cur].f!=-1) que[i+1].push(p[cur].f);
				if(p[cur].m!=-1) que[i+1].push(p[cur].m);
			}	
		}
	}
}

void getIntersection(int lv1,int lv2){
	jiao.clear();
	set_intersection(fam[lv1].begin(),fam[lv1].end(),fam[lv2].begin(),fam[lv2].end(),inserter(jiao,jiao.begin()));
}
int main(){
	
	freopen("data016.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		int id, fa, mo;
//		char ss[2];
//		cin>>id>>ss>>fa>>mo; 
//		scanf("%d %s %d %d",&id,ss,&fa,&mo);
		scanf("%d",&id);
//		printf("%d %d %d\n",i,p[id].f,p[id].m);
		scanf("%s %d %d",p[id].s,&fa,&mo);
//		printf("input: %d %d\n",&fa,&mo);
		p[id].f = fa;
		p[id].m = mo;
		if(fa != -1)   {p[fa].f = -1; p[fa].m = -1;p[fa].s[0]= 'M';}
		if(mo != -1)   {p[mo].f = -1 ;p[mo].m = -1;p[mo].s[0] ='F';}	
	}
	
	int m;
	scanf("%d",&m);
	for(int i = 0;i < m;i++){
		int lv1,lv2;
		scanf("%d%d",&lv1,&lv2);
		if(p[lv1].s[0]==p[lv2].s[0]){printf("Never Mind\n");continue;}
		if(!vis[lv1]){
			vis[lv1] = 1;
			getFam(lv1);
		}
		if(!vis[lv2]){
			vis[lv2] = 1;
			getFam(lv2);
		}
		
//		set<int>::iterator it;
//		for(it = fam[lv1].begin();it!=fam[lv1].end();++it) printf("%d ",*it);
//		printf("\n");
//		
//		for(it = fam[lv2].begin();it!=fam[lv2].end();++it) printf("%d ",*it);
//		printf("\n");
		getIntersection(lv1,lv2);
		if(jiao.size()==0) printf("Yes\n");
		else printf("No\n");
		
	}
	
}

