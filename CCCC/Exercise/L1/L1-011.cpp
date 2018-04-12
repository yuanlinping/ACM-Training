#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const int maxn=10005;
char tar[maxn];
int main(){
	string A,B;
	getline(cin,A);
	getline(cin,B);
	int pos=0;
	for(int i=0;i<A.length();i++){
		string::size_type c=B.find(A[i]);
		if(c!=string::npos) continue;
		else tar[pos++]=A[i];
	}
	printf("%s",tar);
}
