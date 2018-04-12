#include <cstdio>
using namespace std;

const int maxm=10005;
const int maxn=105;
const int maxk=1005;
 
int circle[maxn][maxk];
int query[maxm],handsome[maxm],visited[maxm];;

int main(){
	freopen("data020","r",stdin);
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&circle[i][0]);
		for(int j=1;j<=circle[i][0];j++) scanf("%d",&circle[i][j]);    //本题循环较多，用的计数变量较多，容易写错for里面的句子 
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)scanf("%d",&query[i]);
	int cnt=0,cntv=0;
	
	for(int i=0;i<m;i++){
		int curr=query[i];
		bool isHandsome=true,isVisit=false;
		for(int j=0;j<cntv;j++) if(curr==visited[j]) {isVisit=true;break;}
		if(!isVisit){
			visited[cntv++]=curr;
			for(int j=0;j<n;j++){
		      for(int k=1;k<=circle[j][0];k++) 
				if(circle[j][k]==curr&&circle[j][0]!=1)  {
					isHandsome=false;
					break;
				}
				if(!isHandsome) break;
		    }
			if(isHandsome) 	handsome[cnt++]=curr;
		}	
	}
	if(cnt==0) printf("No one is handsome");
	else{
		for(int i=0;i<cnt-1;i++) printf("%05d ",handsome[i]);
		printf("%d",handsome[cnt-1]);
	}
}
