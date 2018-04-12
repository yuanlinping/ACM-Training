#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=10005;

double grade[maxn];

void swap(int x,int y){
	double tmp=grade[x];
	grade[x]=grade[y];
	grade[y]=tmp;
}

void bubble(int m,int n){   //冒泡排序进行前m个的排序 
	for(int i=0;i<m;i++){
		for(int j=n-1;j>i;j--)
			if(grade[j]>grade[j-1]) swap(j,j-1);
	}
} 

int main(){
//	freopen("data015.txt","r",stdin);
	int n,m,k;
	scanf("%d%d%d",&n,&k,&m);
	for(int i=0;i<n;i++){
		double pg[10];
		memset(pg,0,sizeof(pg));
		for(int j=0;j<k;j++) scanf("%lf",&pg[j]);
		sort(pg,pg+k);
		double sum=0.0;
		for(int x=1;x<k-1;x++) sum+=pg[x];
		grade[i]=sum/(k-2);
	}
	
	bubble(m,n);
	printf("%.3lf",grade[m-1]);
	for(int i=m-2;i>=0;i--) printf(" %.3lf",grade[i]);
	
}
