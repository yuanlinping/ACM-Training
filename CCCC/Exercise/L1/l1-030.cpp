#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
const int maxn=55;

int gen[maxn],vis[maxn];
string name[maxn];
map<string,string>part;

int main(){
//	freopen("data030","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) cin>>gen[i]>>name[i];
	for(int i=0;i<n;i++){
		for(int j=n-1;j>=0;j--){
			if(!vis[i]&&!vis[j]){
				if(gen[i]^gen[j]) {
					part[name[i]]=name[j];
					vis[i]=vis[j]=1;
				}
			}
		}
	}	
	
//	map<string,string>::const_iterator it;    //map貌似会排序，以这种方式输出的话顺序不对 
//	for(it=part.begin();it!=part.end();it++){
//		cout<<it->first<<" "<<it->second<<endl;
//	}

	for(int i=0;i<n/2;i++){
		cout<<name[i]<<" "<<part[name[i]]<<endl;
	}
} 
