#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn=1005;
string str[maxn];

int main(){
	int n;
	scanf("%d",&n);
	int cnt=0,len=0;;
    string ss;
    cin>>ss;
    while(ss[0]!='\n'&&ss[0]!=EOF){
    	len+=ss.length();
    	str[cnt++]=ss;
    	cin>>ss;
	}
	int lentt=len+cnt-1;
	cout<<lentt;
//	int col=ceil()
	
//	cin>>str;
//	scanf("%c",&str[0]);
//	while(scanf("%c",&str[cnt])==1&&str[cnt]!='\n'){cnt++;}
	cout<<str<<" ";
//	<<strlen(str)<<endl;
}
