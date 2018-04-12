#include <cstdio>
//#include <>
using namespace std;

int main(){
	int hh,mm;
	char c;
	scanf("%d%c%d",&hh,&c,&mm);
	if(hh>=0&&hh<12) printf("Only %02d:%02d.  Too early to Dang.",hh,mm);
	else if(mm==0&&hh!=12){
		for(int i=0;i<hh-12;i++) printf("Dang");
	}
	else if(mm==0&&hh==12) printf("Only %02d:%02d.  Too early to Dang.",hh,mm);
	else{
		for(int i=0;i<=hh-12;i++) printf("Dang");
	}
} 
