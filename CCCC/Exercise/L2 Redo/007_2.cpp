#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
const int maxb = 10000;
//int fa[maxn],exs[maxn];   �δ��� 
int fa[maxb],exs[maxb],vis[maxb];   //exs�� ��Ǳ��Ϊi�����Ƿ������и������з��ӵ���   vis�� ��Ǳ��Ϊi�����Ƿ���� 


struct person{   // ���и������з��ӵ��� 
	int ID, num;
	vector<int>mem;   // ���˵����� 
	double ps,par;
	person(int _num = 1, double _ps = 0.0,double _par = 0.0):num(_num),ps(_ps),par(_par){}
}p[maxb];   //�δ��󣺲���p[maxn]

struct family{
	int minId, fnum;
	double as, aar;	
	family(int _fnum = 0,double _as = 0.0,double _aar = 0.0):fnum(_fnum),as(_as),aar(_aar){};
}fam[maxb];  //�δ��󣺲���p[maxn] 

void setP(int id1 ,int id2){   //���кϲ�������ʱ��ͬʱ���и��£�ʹ��ʼ�ձ�����������ͥ����Ϣ 
	fa[id2] = id1;
	p[id1].num += p[id2].num; 
	p[id1].ps += p[id2].ps;
	p[id1].par += p[id2].par;
}

int Find(int id){
	return fa[id] == id? id : fa[id] = Find(fa[id]);
}

void Union(int id1, int id2){
	int fa1 = Find(id1);
	int fa2 = Find(id2);
	if(fa1 != fa2){   //Ҫ�ų��������������setp����Լ����Լ��� 
		if(fa1 > fa2) setP(fa2,fa1);
		else setP(fa1,fa2);
	}
}

bool cmp(const family& a, const family& b) {
	return a.aar > b.aar || (a.aar == b.aar && a.minId < b.minId);
}

int main(){
//	freopen("data007.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i = 0;i < maxb;i++) fa[i] = i;
	
	for(int i = 0; i < n; i++){    //���� 
		int sid, fid, mid, k;
		scanf("%d%d%d%d",&sid,&fid,&mid,&k);
		exs[sid] = 1;
		vis[sid] = 1;
		p[sid].ID = sid;
		if(fid != -1) {p[sid].mem.push_back(fid);vis[fid] = 1;}
		if(mid != -1) {p[sid].mem.push_back(mid); vis[mid] = 1;}
		int kid;
		for(int j = 0;j < k;j++){
			scanf("%d",&kid);
			p[sid].mem.push_back(kid);
			vis[kid] = 1;
		}
		scanf("%lf%lf",&p[sid].ps,&p[sid].par);
		
	}
	
	
	for(int i = 0; i < maxb;i++)   // U/F 
		if(exs[i])   //ֻ���з��ӵĽ��б��� 
			for(int j = 0;j < p[i].mem.size();j++)
				Union(i,p[i].mem[j]);
	
	int cnt = 0;
	for(int i = 0; i < maxb;i++)
		if(vis[i])   //ÿ�����ֵ��˶��л����Ϊ�����ʾ����п��� 
			if(Find(i) == i){
				fam[cnt].minId = i;
				fam[cnt].fnum = p[i].num;
				fam[cnt].as =  p[i].ps / p[i].num;
				fam[cnt].aar = p[i].par /p[i].num;
				cnt++;
			} 
			
	sort(fam,fam+n,cmp);
	
	printf("%d\n",cnt);
	for(int i = 0;i < cnt;i++){
		printf("%04d %d %.3lf %.3lf\n", fam[i].minId,fam[i].fnum,fam[i].as,fam[i].aar);
	}
	
}
