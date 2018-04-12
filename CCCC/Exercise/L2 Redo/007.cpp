#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
const int maxn = 1005;
const int maxb = 10000;
const int maxk = 5;

struct person{
	int mem[3+maxk],fa;
	int k,exist=0;
	double s,ar;
}p[maxb];

struct family{
	int minId, cnt = 0;
	double ts = 0.0, tar = 0.0;
	double as = 0.0, aar = 0.0;	
}fam[maxb];

int Find(int i){
	int fat = p[i].fa;
	return i==fat? i : p[i].fa = Find(fat);
} 

void Union(int i){
	person& ppp = p[i];
	int fa[3+maxk];
	for(int i=0;i<3+ppp.k;i++){
		if(ppp.mem[i]==-1) fa[i]=maxb;
		else fa[i] = Find(ppp.mem[i]);
	}
	int minf=maxb;
	for(int i=0;i<3+ppp.k;i++){
		if(fa[i]<minf) minf=fa[i];
	}
	for(int i=0;i<3+ppp.k;i++){
		p[ppp.mem[i]].fa = minf;
	}
//	int fa1 = Find(i);
//	int fa2 = Find(j);
//	if(fa1==fa2) return;
////	fa1 <= fa2? p[j].fa = fa1 : p[i].fa = fa2;  //并不是将两个本身的元素改了，而是该father的指向
//	fa1 <= fa2? p[fa2].fa = fa1 : p[fa1].fa = fa2; 
	return;
}

bool cmp(const family& a, const family& b) {
	return a.aar > b.aar || (a.aar == b.aar && a.minId < b.minId);
} 

int main(){
	freopen("data007.txt","r",stdin);
	int n;
	scanf("%d",&n);
	rep(i,n) p[i].fa = i;
	rep(i,n){
		int tid;
		scanf("%d",&tid);
		person& pp=p[tid];
		pp.mem[0] = tid;
		pp.exist = 1;
		scanf("%d%d%d",&pp.mem[1],&pp.mem[2],&pp.k);
		for(int j=0;j<pp.k;j++) scanf("%d",pp.mem[3+j]);
		scanf("%ld%ld", &pp.s,&pp.ar);	
		Union(tid);
	}
	
	rep(i,n) Find(i);
	
	rep(i,n){
		if(p[i].exist){
			int fid=p[i].fa;
			fam[fid].minId = fid;
			fam[fid].cnt++;
			fam[fid].ts += p[i].s;
			fam[fid].tar += p[i].ar;
		}
	}
	
	int fcnt = 0;
	rep(i,n){
		if(fam[i].cnt!=0){
			fcnt++;
			fam[i].as = fam[i].ts / fam[i].cnt;
			fam[i].aar = fam[i].tar / fam[i].cnt;
		}
	}	
	
	sort(fam,fam+n,cmp);
	
	printf("%d\n",fcnt);
	for(int i=0;i<fcnt;i++){
		printf("%04d %d %.3lf %.3lf\n", fam[i].minId,fam[i].cnt,fam[i].as,fam[i].aar);
	}
}
