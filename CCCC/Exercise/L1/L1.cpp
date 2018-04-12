#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set> 
using namespace std;

const int maxn=1<<10;//得修改 
int f1,f2,cnt,n,maxc=-maxn,start;
set<int>factor;
int fac[maxn];

//bool isprime(int b){
//	if(b==1||b==2) return true;
//	for(int i=2;i<=sqrt(b);i++){
//		int j=b/i;
//		if(i*j==b) {return false;}	
//	}
//	return true;
//}

bool isprime(int b){
	for(int i=2;i*i<=b;i++){
		if(b%i==0)return false;
	}
	return true;
}
void getFactor(int m){
//	int s=floor(sqrt(m));
//	cout<<m<<endl;
	factor.insert(1);
	factor.insert(m); 
	for(int i=2;i*i<=m;i++){
		if(m%i==0) {
		f1=i;
		f2=m/i;
		factor.insert(f1);
		factor.insert(f2);
//		cout<<f1<<" "<<f2<<endl;
		if(!isprime(f1)) getFactor(f1);
		if(!isprime(f2)) getFactor(f2);
	}
//		bool ok=true;
//		for(int j=0;j<cnt;j++){ //这里要看f1和f2本身一不一样 
//			if(factor[j]==f1||factor[j]==f2){ok=false;break;
//		}
//		if(ok)
	
	}
} 

bool islegal(int d,int c){
	int	multi=1;
	for(int i=d;i<d+c;i++) multi*=fac[i];
	if(multi<=n) return true;
	else return false;
}

void startfrom(int dex,int k){
	if(dex==k) return;
	cnt=1;
	int i;
	for(i=dex+1;i<k;i++){
		if(fac[i]-fac[i-1]==1) cnt++;
		else{
			if((cnt>maxc)&&islegal(dex,cnt)){
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
	getFactor(n);
	set<int>::iterator it;
	int k=0;
	for(it=factor.begin();it!=factor.end();++it)  fac[k++]=*it;
	start=1;
//	cout<<"k="<<k<<endl;
	startfrom(1,k);//从第二个因子开始 
	printf("%d\n",maxc);
	cout<<fac[start];
	for(int i=start+1;i<start+maxc;i++){
		cout<<"*"<<fac[i];
	}
}
