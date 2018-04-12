#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int tr[maxn],d[maxn];

int main(){
	freopen("data014.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d",&tr[i]);
	for(int i = 0; i < n; i++){
		int cur = 0;
		for(int j = 0 ; j < i; j++){
			if(tr[i] > tr[j]) 
				if(d[j] > cur) cur = d[j];
		}
		d[i] = cur + 1;
	}
	int mmax = 0;
	for(int i = 0; i < n; i++) if(mmax < d[i]) mmax = d[i];
	printf("%d",mmax);
} 
