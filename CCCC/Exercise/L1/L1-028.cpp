#include <cstdio>
#include <cmath>
using namespace std;

bool isprime(int a){
	if(a<2) return false;  //本题不认为1是素数 
	int s=floor(sqrt(a));
	for(int i=2;i<=s;i++){    //这个s可以取到的   而且是floor 
		if(a%i==0) return false;
	}
	return true;
}

int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int aa;
		scanf("%d",&aa);
		if(!isprime(aa)) printf("No\n");
		else printf("Yes\n");
	}
}
