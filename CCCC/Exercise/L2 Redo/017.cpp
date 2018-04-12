#include <bits/stdc++.h>
using namespace std;

const int maxn=100005;
const int INF=-2100000000;
int p[maxn];
bool cmp(int i,int j){
	return i>j;
}
int main(){
//	freopen("data017.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	sort(p,p+n,cmp);
	

	int summ=0;
	for(int i=0;i<n;i++) summ+=p[i];
	

	if(n%2==0){
		int sum1=0;
		for(int j=0;j<=(n-1)/2;j++){
			sum1+=p[j];
		}
		int sum2=summ-sum1;
		int dif=sum1-sum2;
		printf("Outgoing #: %d\n",n/2);
	printf("Introverted #: %d\n",n/2);
	printf("Diff = %d",dif);
	}
	
	else{
		int sum1=0;
		for(int j=0;j<=(n-1)/2;j++){
			sum1+=p[j];
		}
		int sum2=summ-sum1;
		int dif1=sum1-sum2;
	
	
		printf("Outgoing #: %d\n",n/2+1);
		printf("Introverted #: %d\n",n/2);
		printf("Diff = %d",dif1);
		}	
	}
