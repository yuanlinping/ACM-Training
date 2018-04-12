#include<iostream>
#include<algorithm> 
using namespace std;
struct shops{
	int F;
	int C;
	int X;
	int P;
}shop[101];
bool ascending(shops a,shops b){
	return a.P<b.P;
}

int main(){
	int K,E,N;
	scanf("%d%d%d",&K,&E,&N);
	
	for(int i=1;i<=N;i++){
		scanf("%d%d%d",&shop[i].X,&shop[i].F,&shop[i].C);
		shop[i].P=E-shop[i].X+shop[i].C;
	}
	
	sort(shop+1,shop+N,ascending);
	
	long long sum=0;
	for(int i=1;i<=N;i++){
		int j=shop[i].F<K?shop[i].F:K;
		sum+=j*shop[i].P;
		K-=j;
		if(K<=0) break;
	}

	  printf("%lld",sum);
return 0;
}
