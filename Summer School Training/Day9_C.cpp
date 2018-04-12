#include <cstdio>
#include<cmath>

using namespace std;

bool isprime(int a){
	int b=(int)sqrt(a);
	for(int i=2;i<=b;i++){
		int c=a/i;
		int d=i*c;
		if(d==a){
			return false;
		}
	}
	return true;
} 

int main(){
	int t;
	while(scanf("%d",&t)){
		if(t==0) return 0; 
		int res=0;
		for(int i=2,j=t-2;i<=j;i++,j--){
			if(isprime(i)&&isprime(j)){
				res++;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
