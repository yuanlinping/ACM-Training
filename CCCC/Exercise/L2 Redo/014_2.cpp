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
		if(cnt==0||rail[cnt-1]<x) rail[cnt++]=x;
		else{
             int l=0, r=cnt-1;
             while(l<r){
                 int mid=l+(r-l)/2;
                 if(rail[mid]>x)
                     r=mid-1;
                 else l=mid+1;
             }
             rail[l]=x;
         }
	}
	printf("%d",cnt);
}
