#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int n;
	char c;
	scanf("%d %c",&n,&c);   //����һ��Ҫ��һ�� �ո� 
//	scanf("%c",&c);
	for(int i=0;i<ceil(n/2.0);i++){
		for(int j=0;j<n;j++) printf("%c",c);
		printf("\n");
	}
}
