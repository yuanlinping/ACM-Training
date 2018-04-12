#include <cstdio>
#include <vector>
using namespace std;

const int maxn=100005;

int rail[maxn];

int main(){
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		bool flag=true;
		for(int j=0;j<cnt;j++){
			if(rail[j]>x){
				rail[j]=x;
				flag=false;
				break;
			}
		}
//		if(flag) {rail.push_back(x);cnt++;  }
		if(flag) rail[cnt++] = x;
		
	}
	printf("%d",cnt);
}
