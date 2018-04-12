//#define LOCAL
#include<iostream>
#include <cstdio>
using namespace std;

const int maxn=1005;

struct stu{
	string ID,testS;
}student[maxn];

int main(){
	#ifdef LOCAL
	freopen("data","r",stdin);
	#endif
	int n,m;
	int query[maxn];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		string temp1;
		int temp2;
		cin>>temp1>>temp2;
		student[temp2].ID=temp1;
		cin>>student[temp2].testS;
	}
	scanf("%d",&m);
	for(int j=0;j<m;j++) scanf("%d",&query[j]);
	for(int i=0;i<m;i++){
		cout<<student[query[i]].ID<<" "<<student[query[i]].testS<<endl;
	}	
	return 0;
} 
