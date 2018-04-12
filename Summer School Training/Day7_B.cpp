#include<cstdio>
#include<stack>
using namespace std;

const int maxn=800005;
int h[maxn];
stack<int>cow;

int main(){
	int N;
	long long sum=0;
	scanf("%d",&N);
	scanf("%d",&h[1]);
	cow.push(h[1]);
	for (int i=2;i<=N;i++){
		scanf("%d",&h[i]);
		while(!cow.empty()&&h[i]>=cow.top()){
			cow.pop();
		}
		sum+=cow.size();
		cow.push(h[i]);
	}
	printf("%lld",sum);
	return 0;
} 
