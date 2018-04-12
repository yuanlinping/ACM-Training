#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int cntbit(int i){
	if(i/10==0) return 1;
	if(i/100==0) return 2;
	if(i/1000==0) return 3;
	else return 4;
}

int num[10];
int main(){
	int n,y;
	cin>>y>>n;
	int xx=y;
	int flag=1;
	while(flag){
		int bit=cntbit(xx);
		int cnt=0;
		memset(num,0,sizeof(num));
		for(int i=0;i<bit;i++) {
			int k=xx%(int)pow(10,i+1)/(int)pow(10,i);
			num[k]++;
		}
		if(bit!=4) num[0]+=1;
		for(int i=0;i<10;i++) if(num[i]!=0) cnt++;
		if(cnt==n){
			flag=0;
		}
		else xx++;
	}
	
	printf("%d %04d",xx-y,xx);
	
}
