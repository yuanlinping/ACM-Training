#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int n,h,rw;
	double nw; 
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&h,&rw);   //���rw��double���͵ģ�����%d����Ļ����䲻��ȥ 
		nw=(h-100)*1.8;
		float cw=abs(rw-nw);
//		printf("%.1f %.1f %d\n",cw,nw,rw);       //��%.1f���int���͵�rw������0.0 
		if(cw<0.1*nw) printf("You are wan mei!\n");
		else if(rw<nw) printf("You are tai shou le!\n");
		else if(nw<rw) printf("You are tai pang le!\n");	
	}
	
} 
