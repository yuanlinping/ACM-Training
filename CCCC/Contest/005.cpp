#include <bits/stdc++.h>
using namespace std;

int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	double res=(double)x/y;
	if(y<0) printf("%d/(%d)=%.2lf",x,y,res);
	else if(y==0) printf("%d/%d=Error",x,y);
	else printf("%d/%d=%.2lf",x,y,res);
}
