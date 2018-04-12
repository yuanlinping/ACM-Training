#include <cstdio>
#include <stack>
//#include <cmath>
using namespace std;

const int maxn=505;
const int INF=1000;
int edge[maxn][maxn];
int team[maxn],path[maxn];
//vector<int>PMark;
//int Visited;
struct city{
	int dis=INF,pre=0,t;
	bool P=false;
}city[maxn]; 

int main(){
	int N,M,S,D;
	scanf("%d%d%d%d",&N,&M,&S,&D);
	for(int i=0;i<N;i++) {
		scanf("%d",&city[i].t);
	}
	int c1,c2,len;
	while(M){
		scanf("%d%d%d",&c1,&c2,&len);
		edge[c1][c2]=edge[c2][c1]=len;
		M--;
	}
	
	city[S].P=true;
	team[S]=city[S].t;
	path[S]=1;
//	PMark.push_back(S);
	int T=S;
	city[T].dis=0;
	while(T!=D){
		for(int i=0;i<N;i++){
			if(edge[T][i]!=0&&!city[i].P){
				city[i].dis=min(city[i].dis,city[T].dis+edge[T][i]);
			}
		}
		int TIndex;
		for(int i=0;i<N;i++){
			if(!city[i].P) {TIndex=i;break;}
		}
		for(int i=0;i<N;i++){
			if(!city[i].P){
				TIndex=city[TIndex].dis>city[i].dis?i:TIndex;
			}
		}
		city[TIndex].P=true;
		city[TIndex].pre=T;    //pre更新有误，不一定就是现在的T。但是如何找到呢？？ 
		T=TIndex;
	}
	
	stack<int>path;
	path.push(D);
	int temp=D;
	while(city[temp].pre!=S){
		temp=city[temp].pre;
		path.push(temp);
	}
	stack<int>copyPath;
	copyPath=path;
	int cnt=team[S];
	while(!copyPath.empty()) {cnt+=team[copyPath.top()];copyPath.pop();}
	printf("%d %d\n",path.size()+1,cnt);
	printf("%d",S);
	while(!path.empty()){printf(" %d",path.top());path.pop();} 
}
