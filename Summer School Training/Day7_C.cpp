#include<iostream>
#include<cstdio>
#include<queue>
#include<functional>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

const int maxn=2505;
int res=0;
priority_queue<int,vector<int>,greater<int> >que;

struct cows{
   int minspf;
   int maxspf;
}cow[maxn];

struct lotion{
	int spf;
	int amt;
}lot[maxn];

bool cmp(cows a,cows b){
//	return a.maxspf==b.maxspf?a.minspf<b.minspf:a.maxspf<b.maxspf;  //先按最大值排，最大值一样按最小值排 
    return a.minspf<b.minspf;
}

bool cmp2(lotion a,lotion b){
	return a.spf<b.spf;
}



int main(){
	int C,L;
	scanf("%d%d",&C,&L);
	for(int i=0;i<C;i++){
		scanf("%d%d",&cow[i].minspf,&cow[i].maxspf);
	}
	
	for(int i=0;i<L;i++){
		scanf("%d%d",&lot[i].spf,&lot[i].amt);
	}
	
	sort(cow,cow+C,cmp);
	sort(lot,lot+L,cmp2);
	
	int j=0;
	for(int k=0;k<L;k++){
		while(j<C&&lot[k].spf>=cow[j].minspf){
			que.push(cow[j].maxspf);
			j++; 
		}
		while(!que.empty()&&lot[k].amt){
			int temp=que.top();
			que.pop();
			if(temp<lot[k].spf) continue;
			res++;
			lot[k].amt--;
		}
	}

	printf("%d",res);
	return 0;	
}
 
