#include <cstdio>
#include <vector>
using namespace std;

const int maxn=100005;

vector<int>rail[maxn];

int main(){
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		bool flag=true;
		for(int j=0;j<cnt;j++){
			if(rail[j].back()>x){
				rail[j].push_back(x);
				flag=false;
				break;
			}
		}
		if(flag) rail[cnt++].push_back(x);
	}
	printf("%d",cnt);
}
