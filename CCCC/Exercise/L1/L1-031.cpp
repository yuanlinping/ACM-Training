#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int n,h,rw;
	double nw; 
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&h,&rw);   //如果rw是double类型的，但是%d输入的话，输不进去 
		nw=(h-100)*1.8;
		float cw=abs(rw-nw);
//		printf("%.1f %.1f %d\n",cw,nw,rw);       //以%.1f输出int类型的rw，都是0.0 
		if(cw<0.1*nw) printf("You are wan mei!\n");
		else if(rw<nw) printf("You are tai shou le!\n");
		else if(nw<rw) printf("You are tai pang le!\n");	
	}
	
} 
