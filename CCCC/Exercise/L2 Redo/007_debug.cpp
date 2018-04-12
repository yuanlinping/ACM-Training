#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
const int maxb = 10000;
int fa[maxb],exs[maxb];

struct person{
	int ID, num ;
	vector<int>mem;
	double ps ,par;
	bool isp;
	person(int _num = 1, double _ps = 0.0,double _par = 0.0,bool _isp = true):num(_num),ps(_ps),par(_par),isp(_isp)
	 {}
}p[maxb];

int main(){
//	freopen("007da","r",stdin);
	for(int i = 0;i < 5;i++){
		printf("%04d ",p[i].ID);
		for(int j = 0;j < p[i].mem.size();j++) printf("%d ",p[i].mem[j]);
		printf("%ld %ld\n",p[i].ps,p[i].par);
	}
	int n;
	scanf("%d",&n);
	for(int i = 0;i < maxb;i++) fa[i] = i;
	for(int i = 0; i < n; i++){
		int sid, fid, mid, k;
		scanf("%d%d%d%d",&sid,&fid,&mid,&k);
		exs[sid] = 1;
		p[sid].ID = sid;
		if(fid != -1) p[sid].mem.push_back(fid);
		if(mid != -1) p[sid].mem.push_back(mid);
		int kid;
		for(int j = 0;j < k;j++){
			scanf("%d",&kid);
			p[sid].mem.push_back(kid);
		}
		scanf("%ld%ld",&p[sid].ps,&p[sid].par);
		
		if(i == n-1)for(int j = 5550;j <= 6666;j++) {printf("%d ",exs[j]);printf("\n");}
	 
//		printf("i = %d\n",i);
//		printf("%04d ",p[sid].ID);
//			for(int j = 0;j < p[sid].mem.size();j++) printf("%d ",p[sid].mem[j]);
//			printf("%ld %ld\n",p[sid].ps,p[sid].par);
	}
}
