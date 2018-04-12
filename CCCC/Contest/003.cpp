#include <bits/stdc++.h>
using namespace std;

const int maxn=10005;
char name[maxn][20];

int main(){
	freopen("002.txt","r",stdin);
	char curr[20];
	int cnt=0;
	while(scanf("%s",curr)==1&&curr[0]!='.'){
		strcpy(name[cnt],curr);
		cnt++;
	}
	if(cnt>=14) printf("%s and %s are inviting you to dinner...",name[1],name[13]);
	else if(cnt>=2) printf("%s is the only one for you...",name[1]);
	else printf("Momo... No one is for you ...");
}
