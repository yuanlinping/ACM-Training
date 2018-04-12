#include <cstdio>
using namespace std;

int main(){
	int d;
	scanf("%d",&d);
	int h=(d+2)%7;
	if(h==0)printf("%d",7);
	else printf("%d",h);
} 
