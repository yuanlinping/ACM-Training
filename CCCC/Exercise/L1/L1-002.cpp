#include <cstdio>
#include <cmath> 
using namespace std;

void print(int len,char c){
	for(int i=0;i<len;i++) printf("%c",c);
}
int main(){
	int N,k;
	char t;
	scanf("%d %c",&N,&t);
	k=1;
	while((k+1)*(k+1)/2-1<=N) k++;
	if(k%2==0)k-=1;
	else k-=2;
	int rest=N-(k+1)*(k+1)/2+1;
	//´òÓ¡
	int i=0;
	while(i<=(k-1)/2){
		print(i,' ');
		print(k-2*i,t);
//		print(i,'_');
		printf("\n");
		i++;
	} 
	i=i-2;
	while(i>=0){
		print(i,' ');
		print(k-2*i,t);
//		print(i,'_');
		printf("\n");
		i--;
	}
	printf("%d\n",rest);
} 
