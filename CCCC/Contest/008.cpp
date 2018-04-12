#include <bits/stdc++.h>
using namespace std;


int main(){
//		freopen("002.txt","r",stdin);

	int n;
	scanf("%d",&n);
	printf("%d\n",n);
	for(int i=0;i<n;i++){
		char s;
		double h;
		cin>>s>>h;
//		scanf("%c %lf",&s,&h);
		if(s=='M') printf("%.2lf\n",h/1.09);
		else printf("%.2lf\n",h*1.09);
	}
}
