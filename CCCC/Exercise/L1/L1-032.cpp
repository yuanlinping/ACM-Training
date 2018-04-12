#include <iostream>
#include <cstdio>
using namespace std;

void print(int cnt,char c){
	for(int i=0;i<cnt;i++) printf("%c",c);
}

int main(){
	int n;
	char sg;
	scanf("%d %c ",&n,&sg);  //当时整数和字符串同时输入的时候，“”说明中需要空格 
	string line;
	getline(cin,line);
	int len=line.length();
	if(n>len){
		int cnt=n-len;
		print(cnt,sg);
		cout<<line;
	}
	else{
		int in=len-n;
		for(int i=in;i<len;i++) printf("%c",line[i]); 
	}
	
}
