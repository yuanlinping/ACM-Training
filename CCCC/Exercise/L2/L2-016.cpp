#include<cstdio>
#include<iostream>
#include<set>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
const int maxn=10005; 

struct person{
	int ft[2];
	set<int>fam;
	char g[2];
}p[maxn];

int visited[maxn];
set<int>jiao;

void getIntersection(int i,int j){
	jiao.clear();
	set_intersection(p[i].fam.begin(),p[i].fam.end(),p[j].fam.begin(),p[j].fam.end(),inserter(jiao,jiao.begin()));
}

int main(){
	freopen("data016.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x); 
//		cin>> p[x].g >> p[x].ft[0]>> p[x].ft[1];
		scanf("%s %d %d",p[x].g,&p[x].ft[0],&p[x].ft[1]);    // 尽量不要用%c读取   在这里你的%c会读取到空格   除了上述的做法 你可以开一个小的字符数组，然后用%s读取
		visited[x]=1;
	}
	
//	printf("chenggong1\n");
//	for(int x=0;x<=25;x++)
////cout<<x<<" "<<p[x].g<<" "<<p[x].ft[0]<<" "<<p[x].ft[1]<<endl;
//	printf("%d %s %d %d\n",x,p[x].g,p[x].ft[0],p[x].ft[1]);
//	printf("\n");
	
	for(int i=0;i<10000;i++){
		if(visited[i]){
			queue<int>ff;
		    ff.push(i);
		    int cnt=0;
			while(!ff.empty()&&cnt<31){
				
				int cur=ff.front();
				printf("%d ",cur);
				ff.pop();
				if(visited[cur]==0){
					ff.push(-1);
					ff.push(-1);
					p[i].fam.insert(cur);
				}
				if(cur==-1){
					ff.push(-1);
					ff.push(-1);
				}
				else{
					ff.push(p[cur].ft[0]);
					ff.push(p[cur].ft[1]);
					p[i].fam.insert(cur);
				}    
				cnt+=1;
			}	
		}

	}
//	printf("chenggong2\n");
	
	set<int>::iterator it;
	for(it=p[24].fam.begin();it!=p[24].fam.end();++it) printf("%d ",*it);
	printf("\n");
//	
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		if(!strcmp(p[v1].g,p[v2].g)) printf("Never Mind.\n");
		else{
			getIntersection(v1,v2);
			int sz=jiao.size();
			if(sz==0) printf("Yes\n");
			else printf("No\n");
		}
	}
	
//	printf("chenggong3\n");
}
