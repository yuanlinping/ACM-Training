#include <cstdio>
#include <cmath>
using namespace std;

bool isprime(int a){
	if(a<2) return false;  //���ⲻ��Ϊ1������ 
	int s=floor(sqrt(a));
	for(int i=2;i<=s;i++){    //���s����ȡ����   ������floor 
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
