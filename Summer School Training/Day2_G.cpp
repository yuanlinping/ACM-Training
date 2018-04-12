#include<iostream>
#include<algorithm>
using namespace std;
int p1,p2,N,cnt;
struct prog{      
	int st;
	int en;
}pro[155]; 

bool compare(prog a,prog b){
	return a.en<b.en;
}

int main()
{
scanf("%d",&N);
for(int i=0;i<N;i++)scanf("%d%d",&pro[i].st,&pro[i].en);     //ÊäÈëÊ±¼ä 

sort(pro,pro+N,compare);
p1=-1;p2=-1;cnt=0;
  	for(int i=0;i<N;i++)
  	{
    if((pro[i].st<p1)&&(pro[i].st<p2))continue;
    if((pro[i].st>=p1)&&(pro[i].st<p2))
    {
      cnt++;
  p1=pro[i].en;
      continue;
    }
    if((pro[i].st>=p2)&&(pro[i].st<p1))
    {
      cnt++;
  p2=pro[i].en;
      continue;
    }
    if(pro[i].st>=p1&&pro[i].st>=p2&&pro[i].st-p1<=pro[i].st-p2)
    {
      cnt++;
  p1=pro[i].en;
      continue;
    }
    else{
      cnt++;
  p2=pro[i].en;
      continue;
    }
  }
  printf("%d",cnt);
}
