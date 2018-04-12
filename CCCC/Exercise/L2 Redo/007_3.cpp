#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
const int maxb = 10000;
int fa[maxb],exs[maxb];


struct person{
	int ID, num = 1;
	vector<int>mem;
	double ps = 0.0,par = 0.0;
	bool isp = true;
}p[maxb];   

struct family{
	int minId, fnum;
//	double ts = 0.0, tar = 0.0;
	double as, aar;	
}fam[maxb];  //不是p[maxn] 

void setP(int id1 ,int id2){
	fa[id2] = id1;
//	p[id1].isp = true;  
	p[id1].num += p[id2].num; 
	p[id1].ps += p[id2].ps;
	p[id1].par += p[id2].par;
	p[id2].isp = false; 
}

int Find(int id){
	return fa[id] == id? id : fa[id] = Find(fa[id]);
}

void Union(int id1, int id2){
	int fa1 = Find(id1);
	int fa2 = Find(id2);
	if(fa1 != fa2){
		if(fa1 > fa2) setP(fa2,fa1);
		else setP(fa1,fa2);
	}
}

bool cmp(const family& a, const family& b) {
	return a.aar > b.aar || (a.aar == b.aar && a.minId < b.minId);
}

int main(){
	freopen("data007.txt","r",stdin);
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
		
//		if(i == n-1)for(int j = 5550;j <= 6666;j++) {printf("%d ",exs[i]);printf("\n");}
	 
//		printf("i = %d\n",i);   //   这个打印出来是  很多很多零 
//		printf("%04d ",p[sid].ID);
//			for(int j = 0;j < p[sid].mem.size();j++) printf("%d ",p[sid].mem[j]);
//			printf("%ld %ld\n",p[sid].ps,p[sid].par);
	}
	
		for(int i = 0; i < maxb;i++)
		if(exs[i]){
			printf("%04d ",p[i].ID);
			for(int j = 0;j < p[i].mem.size();j++) printf("%d ",p[i].mem[j]);
			printf("%ld %ld\n",p[i].ps,p[i].par);
		}
	
	for(int i = 0; i < maxb;i++)
		if(exs[i])
			for(int j = 0;j < p[i].mem.size();j++)
				Union(i,p[i].mem[j]);
	
	int cnt = 0;
	for(int i = 0; i < maxb;i++)
		if(!((p[i].ps-0.0) < 1e-7))
			if(p[i].isp){
				fam[cnt].minId = i;
				fam[cnt].fnum = p[i].num;
				fam[cnt].as = p[i].ps / p[i].num;
				fam[cnt].aar = p[i].par /p[i].num;
				cnt++;
			} 
			
	sort(fam,fam+n,cmp);
	
//	printf("%d\n",cnt);
	for(int i = 0;i < cnt;i++){
		printf("%04d %d %.3lf %.3lf\n", fam[i].minId,fam[i].fnum,fam[i].as,fam[i].aar);
	}
	
}
