//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn=1005;
char str[maxn];
int main(){
	freopen("002.txt","r",stdin);
	int n;
	cin>>n;
	string str;
	getline(cin,str);
	int len=str.length();
	int col=ceil(len/n);
		for(int j=0;j<n;j++){
			int st=(col-1)*n;
			for(int x=0;x<col;x++){
				if(x==0&&st>len) continue;
				printf("%c",str[st-n]);
		}
		printf("\n");
	}

//	printf("%d",str.length());
}
