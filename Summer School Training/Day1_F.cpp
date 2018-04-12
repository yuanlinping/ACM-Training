#include <iostream>
using namespace std;
const int maxn=15;
const int range=10^5;
int c[range];
int fit[maxn];
bool fun(int a,int k){
	int bit=0;
	while(a){
		c[bit]=a%k;
		a=a/k;
		bit++;
	}
	int st=0,en=bit-1;
	while(st<en)	    
	{
	    if(c[st]!=c[en]) return false;
	    st++;en--;
	}
	//if(c[0]==0) return false;
	return true;
}


int f(int a) {
	int j=0;
	for(int i=2;i<=10;i++) {
		if(fun(a,i))
			j++;
	}
	return j;
}
int main() {
	int N,S;
	cin>>N>>S;
	int ans=0;
	int i=1,l=0;
    while(ans<N){
			int a=S+i;
			int q=f(a);
		    if(q>=2)
			    {fit[l]=a;l++;ans++;}
			i++;
	}
	
	for(int m=0;m<l-1;m++){
		cout<<fit[m]<<endl;
	}
	cout<<fit[l-1];

		return 0;
}
