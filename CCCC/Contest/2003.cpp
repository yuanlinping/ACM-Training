#include <bits/stdc++.h>
using namespace std;

const int maxn=100005;
int sf[maxn];
int ddz[maxn];
int glzz[maxn];

int ds;

void findds(int i){
	if(sf[i]==0) {ds++;return;}
	ds++;
	findds(sf[i]);
}


int main(){
	sf[0]=0;
	freopen("002.txt","r",stdin);
	int n;
	double z,r;
	scanf("%d %lf %lf",&n,&z,&r);
	int cnt=0;
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		if(k==0){ddz[cnt++]=i;scanf("%d",&glzz[i]);}
		else{
//			cout<<"k="<<k<<endl;
		for(int j=0;j<k;j++){
			int x;
			scanf("%d",&x);
			sf[x]=i;
//			cout<<sf[x]<<" "<<x<<endl;
		}	
		
		}
		
	}
	
//	for(int i=0;i<n;i++) cout<<sf[i]<<" ";
//	cout<<endl;
	
	double sum=0.0;
//	int sum=0;
	for(int i=0;i<cnt;i++){
		ds=0;
		findds(ddz[i]);
		double ysgl=z;
		for(int j=0;j<ds;j++){
			ysgl=ysgl*(100-r)/100;
		}
		ysgl*=glzz[ddz[i]];
		sum+=ysgl;		
	}
	int summ=(int)(sum);
	printf("%d",summ);
	
	
	
}
