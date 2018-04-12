#include <cstdio>
using namespace std;

int main(){
	int A,B;
	scanf("%d%d",&A,&B);
	int sum=0,cnt=0;
	for(int i=A;i<=B;i++){
		cnt++;
//		if(cnt%5==1) printf("%d",i);
		printf("%5d",i);
		sum+=i;
		if(cnt%5==0) printf("\n");
	}
	if(cnt%5==0) printf("Sum = %d",sum);
	else printf("\nSum = %d",sum);
	return 0;
} 
