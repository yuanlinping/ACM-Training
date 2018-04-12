#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set> 
#include<cstring>
using namespace std;

const int maxn=1<<16;//得修改 
int f1,f2,cnt,n,maxc=-maxn,start;
set<int>factor;
int fac[maxn];
int vis[maxn];

bool isprime(int b){ //判断是否是质数（把1当成质数了） 
	for(int i=2;i*i<=b;i++){
		if(b%i==0)return false;
	}
	return true;	
}
void getFactor(int m){   //算出所有因子 
	vis[m]=1;
	factor.insert(1);
	factor.insert(m); 
	for(int i=2;i*i<=m;i++){
		if(m%i==0) {
		f1=i;
		f2=m/i;
//		cout<<m<<" "<<f1<<" "<<f2<<endl;
		factor.insert(f1);
		factor.insert(f2);
		if(!isprime(f1)&&!vis[f1]) getFactor(f1);
		if(!isprime(f2)&&!vis[f2]) getFactor(f2);
    	}
	}
} 

void startfrom(int dex,int k){
	if(dex==k) return;
	cnt=1;
	int i,multi=fac[dex];
	for(i=dex+1;i<k;i++){
		if(fac[i]-fac[i-1]==1){
			multi*=fac[i];
			if(multi<=n) cnt++;
//			cout<<multi<<" "<<cnt<<" "<<endl;
		} 
		else{
			if((cnt>maxc)){
				maxc=cnt;
				start=dex;
			}
			break;
		}
	}
	startfrom(i,k);
}


int main(){
	scanf("%d",&n);
	memset(vis,0,sizeof(vis));
	getFactor(n);
	set<int>::iterator it;
	int k=0;
	for(it=factor.begin();it!=factor.end();++it)  fac[k++]=*it;
//	for(int i=0;i<k;i++) cout<<fac[i]<<endl;
	start=1;
	startfrom(1,k);//从第二个因子开始 
	printf("%d\n",maxc);
	cout<<fac[start];
	for(int i=start+1;i<start+maxc;i++){
		cout<<"*"<<fac[i];
	}
}
